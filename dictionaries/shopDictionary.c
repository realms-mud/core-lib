//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#include "/lib/include/itemFormatters.h"

private string BaseShop = "lib/environment/shopInventories/baseShop.c";

private mapping alwaysGenerate = ([
    "weapons":([
        "daggers":({ "dagger", "dirk", "knife", "stiletto" }),
        "swords":({ "bastard-sword", "broad-sword", "claymore", "long-sword", "short-sword" }),
        "staffs":({ "quarterstaff", "shield-staff", "staff", "swordstaff" }),
        "axes":({ "axe", "battle-axe", "bearded-axe", "hatchet", "broad-axe", "splitting-maul" }),
        "pole-arms":({ "bardiche", "brandistock", "glaive", "halberd", "lance", "military-fork", "pike", "pitchfork", "spear", "trident" }),
        "hammers":({ "horsemans-pick", "lucerne-hammer", "maul", "war-hammer" }),
        "maces":({ "club", "flanged-mace", "mace", "morning-star" }),
        "flails":({ "flail", "whip", "military-flail", "hinged-flail" }),
        "crossbows":({ "crossbow", "levered-crossbow", "cranequin-crossbow" }),
        "bows":({ "short-bow", "bow", "long-bow", "recurve-bow", "composite-bow"}),
        "slings":({ "kestros", "sling", "slingshot", "sling-staff" }),
        "thrown":({ "dart", "javelin", "rock", "throwing-axe", "throwing-hammer", "throwing-spear" }),
        "shields":({ "shield", "buckler", "heater-shield", "kite-shield", "spiked-shield", "pavise-shield" })
    ]),
    "armor":([
        "medium armor":({ "chainmail", "boiled-leather", "hard-leather", "lamellar-leather", "ring-mail"}),
        "light armor":({ "gambeson", "soft-leather", "leather-jacket", "padded-armor", "leather-arm-greaves", "leather-leg-greaves"}),
        "heavy armor":({ "breastplate", "brigandine", "plate-armor", "scale-armor", "splint-mail", "plate-leg-greaves", "plate-arm-greaves"}),
        "clothing":({ "cloak", "robes", "dress", "shirt", "pants", "skirt", "gown"}),
        "accessories":({ "belt", "boots", "helmet" }),
    ])
]);

/////////////////////////////////////////////////////////////////////////////
public nomask object getShopObject(string location)
{
    object ret = 0;

    if (location && stringp(location) && location[0] != '/')
    {
        location = "/" + location;
    }

    if (location && stringp(location) && (file_size(location) > 0))
    {
        ret = clone_object(location);

        if (!ret || (member(inherit_list(ret), BaseShop) < 0))
        {
            ret = 0;
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *getSellItemTypes(object user)
{
    string *ret = ({});

    object *items = deep_inventory(user) - 
        user->registeredInventoryObjects();

    if (sizeof(items))
    {
        foreach(object item in items)
        {
            if (member(ret, item->query("type")) < 0)
            {
                ret += ({ item->query("type") });
            }
        }
    }
    return ret - ({ 0 });
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs float valueModifier(object user, int selling)
{
    float multiplier = 0.05 + (user->charismaBonus() / 20.0);
    if (user->getSkill("bluff"))
    {
        multiplier += (user->getSkillModifier("bluff") / 100.0);
    }
    if (user->getSkill("intimidation"))
    {
        multiplier += (user->getSkillModifier("intimidation") / 100.0);
    }
    if (user->getSkill("persuasion"))
    {
        multiplier += (user->getSkillModifier("persuasion") / 100.0);
    }
    if (user->getSkill("barter"))
    {
        multiplier += (user->getSkillModifier("barter") / 25.0);
    }
    if (multiplier > 0.85)
    {
        multiplier = 0.85;
    }
    if (!selling)
    {
        multiplier = 1.6 - multiplier;
    }

    if (multiplier < 0.05)
    {
        multiplier = 0.05;
    }

    return multiplier;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getSellItemDetailsForType(object user, string type, object store)
{
    mapping ret = ([]);
    int menuItem = 1;

    object *items = filter(deep_inventory(user) -
        user->registeredInventoryObjects(),
        (: (($1->query("type") == $2) && !$3->isModifierItem($1)) :), 
        type, user);

    object materials = load_object("/lib/dictionaries/materialsDictionary.c");
    if (sizeof(items))
    {
        float multiplier = valueModifier(user, 1);
        foreach(object item in items)
        {
            int value = to_int(item->query("value") * multiplier);
            value = (value < 25000) ? value : 25000;

            string valueStr = value ?
                sprintf("\x1b[0;32mYou can sell this item for %d.\x1b[0m\n", value) :
                "\x1b[0;32mThis item has no value to the merchant.\x1b[0m\n";

            string name = item->query("name");

            ret[to_string(menuItem)] = ([
                "name": sprintf(materials->getMaterialQualityFormatter(item, user),
                    ((sizeof(name) > 20) ? name[0..16] + "..." : name)),
                "identified": item->query("identified"),
                "object list": ({ item }),
                "description": item->long(1) + valueStr,
                "value": value
            ]);

            if (user->isEquipped(item))
            {
                ret[to_string(menuItem)]["is equipped"] = 1;
            }
            if (item->query("no sell") || !store->canPurchaseItem(item))
            {
                ret[to_string(menuItem)]["do not sell"] = 1;
            }
            if (item->query("identified") && item->query("cursed"))
            {
                ret[to_string(menuItem)]["known cursed item"] = 1;
            }
            else if(item->query("cursed"))
            {
                ret[to_string(menuItem)]["unknown cursed item"] = 1;
            }
            menuItem++;
        }

        ret[to_string(menuItem)] = ([
            "name": "\x1b[0;30;1mSell all" + 
                ((member(({ "armor", "weapon", "instrument" }), type) > -1) ?
                    " unused\x1b[0m    " : ""),
            "description": "This option will sell all of your unequipped " + type,
            "object list": filter(items, 
                (: (!$2->isEquipped($1) && !$1->query("cursed") &&
                   !$1->query("no sell")) :), user)
        ]);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask void moveNestedItemsToUser(object user, object item)
{
    object *nestedItems = all_inventory(item);
    if (sizeof(nestedItems))
    {
        foreach(object nestedItem in nestedItems)
        {
            move_object(nestedItem, user);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void sellItems(object user, object store, object *items)
{
    int money = 0;
    if (sizeof(items))
    {
        float multiplier = valueModifier(user, 1);
        foreach(object item in items)
        {
            moveNestedItemsToUser(user, item);

            if (user->isEquipped(item))
            {
                item->unequip(item->query("name"), 1);
            }

            // If the item's still equipped, it can't be sold
            if (!user->isEquipped(item))
            {
                int value = to_int(item->query("value") * multiplier);
                value = (value < 25000) ? value : 25000;
                money += value;
                tell_object(user, sprintf("\x1b[0;32mYou sell %s.\x1b[0m\n",
                    item->query("name")));
                store->storeItem(item);
                destruct(item);
            }
        }
    }
    if (money)
    {
        user->addMoney(money);
    }
    tell_object(user, sprintf("\x1b[0;37mYou received $%d for your sold items.\x1b[0m\n",
        money));
}

/////////////////////////////////////////////////////////////////////////////
private nomask void generateDefaultItems(object shop)
{
    string type = shop->shopType();
    string subType = shop->shopSubType();

    string dir = sprintf("/lib/instances/items/%s%s/", type,
        ((subType != "all") ? "/" + regreplace(subType, " ", "-", 1)
        : ""));

    string *defaultItems = ({});
    if (member(alwaysGenerate, type) && member(alwaysGenerate[type], subType))
    {
        defaultItems = alwaysGenerate[type][subType];
    }
    else if (member(alwaysGenerate, type) && (subType == "all"))
    {
        string *directories = m_indices(alwaysGenerate[type]);
        if (sizeof(directories))
        {
            foreach(string directory in directories)
            {
                foreach(string item in alwaysGenerate[type][directory])
                {
                    defaultItems += ({ sprintf("%s/%s", directory, item) });
                }
            }
        }
    }

    object craftingDictionary = load_object("/lib/dictionaries/craftingDictionary.c");
    if (sizeof(defaultItems))
    {
        foreach(string itemName in defaultItems)
        {
            object item = clone_object(sprintf("%s%s.c", dir, itemName));
            craftingDictionary->getRandomCraftingMaterial(item, 1);

            item->identify();
            shop->storeItem(item, 1);
            destruct(item);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void generateRandomItems(object shop)
{
    int numItems = shop->randomItemsToGenerate();

    object materials = load_object("/lib/dictionaries/materialsDictionary.c");

    for (int i = 0; i < numItems; i++)
    {
        object item = materials->generateRandomItem(shop->shopType(),
            (shop->shopSubType() != "all") ? shop->shopSubType() : "",
            100);

        item->identify();
        shop->storeItem(item);
        destruct(item);
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void generateInventory(object shop)
{
    if (shop->shopSubType() != "all")
    {
        generateRandomItems(shop);
    }
    generateDefaultItems(shop);
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *getBuyItemTypes(object store)
{
    string *types = ({});
    mapping inventory = store->storeInventory();
    string *inventoryItems = m_indices(inventory);

    if (sizeof(inventoryItems))
    {
        foreach(string item in inventoryItems)
        {
            string itemType = inventory[item]["type"];
            if (member(inventory[item], "subType") &&
                inventory[item]["subType"])
            {
                itemType += "s - " + 
                    capitalize(inventory[item]["subType"]);
            }
            if (member(types, itemType) < 0)
            {
                types += ({ itemType });
            }
        }
    }
    return types;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getBuyItemDetailsForType(object store, string type, string subtype)
{
    mapping inventory = store->storeInventory();
    string *itemList = m_indices(filter_indices(inventory,
        (: (($2[$1]["type"] == $3) && 
           (($4 == "all") || ($2[$1]["subType"] == $4))) :), 
            inventory, type, subtype));
    mapping ret = ([]);
    if (sizeof(itemList))
    {
        itemList = sort_array(itemList, (: $1 > $2 :));
        int menuItem = 1;
        foreach(string item in itemList)
        {
            string valueStr = sprintf("\x1b[0;32mYou can buy this item for %d.\x1b[0m\n",
                inventory[item]["value"]);

            string qualityFormat = regreplace(inventory[item]["quality"],
                "(.*)%(-20|)s(.*)", "\\1%-23s\\3", 1);

            ret[to_string(menuItem)] = ([
                "name": sprintf("%s \x1b[0;32m%8d\x1b[0m",
                    sprintf(qualityFormat, 
                    ((sizeof(inventory[item]["name"]) <= 23) ? inventory[item]["name"] :
                        inventory[item]["name"][0..19] + "...")),
                    inventory[item]["value"]),
                "description": inventory[item]["description"] + valueStr,
                "data": inventory[item]["data"],
                "value": inventory[item]["value"],
                "summary": inventory[item]["summary"],
                "blueprint": regreplace(item, "([^#]+)#.*", "/\\1.c", 1),
                "key": item
            ]);
            menuItem++;
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void buyItem(object user, object store, mapping item)
{
    int money = 0;
    if (sizeof(item) && member(item, "blueprint") &&
        member(item, "value") && member(item, "data"))
    {
        if (user->Money() >= item["value"])
        {
            object itemObj = clone_object(item["blueprint"]);
            itemObj->set("all", item["data"]);
            itemObj->set("value", item["value"]);
            user->addMoney(-item["value"]);
            store->buyItem(item["key"]);
            move_object(itemObj, user);
            tell_object(user, sprintf("\x1b[0;32mYou purchased %s for $%d.\x1b[0m\n",
                itemObj->query("name"), item["value"]));
        }
        else
        {
            tell_object(user, "\x1b[0;32mYou do not have the funds for that.\x1b[0m\n");
        }
    }
}

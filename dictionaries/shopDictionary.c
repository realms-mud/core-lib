//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#include "/lib/include/itemFormatters.h"

private string BaseShop = "lib/environment/shopInventories/baseShop.c";
private object configuration = load_object("/lib/dictionaries/configurationDictionary.c");

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
private string materialQualityFormatter(string formatter,
    string colorConfiguration)
{
    string type = regreplace(formatter, "%s [(](C|E|M|P)[)]", "\\1");
    string decoration = "";
    switch (type)
    {
        case "C":
        {
            decoration = "well-crafted";
            break;
        }
        case "E":
        {
            decoration = "enchanted";
            break;
        }
        case "M":
        {
            decoration = "masterwork";
            break;
        }
        case "P":
        {
            decoration = "powerful enchantment";
            break;
        }
        default:
        {
            decoration = "normal quality";
            break;
        }
    }

    string formatString = (colorConfiguration == "none") ? 
        regreplace(formatter, "(.*)%s(.*)", "\\1%-20s\\2", 1) : "%-23s";

    return configuration->decorate(formatString, decoration, "equipment",
        colorConfiguration);
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
        string colorConfiguration = user->colorConfiguration() ?
            user->colorConfiguration() : "none";

        float multiplier = valueModifier(user, 1);
        foreach(object item in items)
        {
            int value = to_int(item->query("value") * multiplier);
            value = (value < 25000) ? value : 25000;

            string valueStr = value ?
                sprintf("You can sell this item for %d.\n", value) :
                "This item has no value to the merchant.\n";

            string name = item->query("name");

            string materialFormat = regreplace(materialQualityFormatter(
                materials->getMaterialQualityFormatter(item),
                colorConfiguration), "%-23s", "%-19s", 1);

            ret[to_string(menuItem)] = ([
                "name": sprintf(materialFormat,
                    ((sizeof(name) > 19) ? name[0..15] + "..." : name)),
                "identified": item->query("identified"),
                "object list": ({ item }),
                "description": item->long(1) + 
                    configuration->decorate(valueStr, "message", "shop",
                    colorConfiguration),
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
            "name": configuration->decorate("Sell all" +
                ((member(({ "armor", "weapon", "instrument" }), type) > -1) ?
                    " unused    " : ""), "sell all", "shop", 
                colorConfiguration), 
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
    string colorConfiguration = user->colorConfiguration() ?
        user->colorConfiguration() : "none";

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
                tell_object(user, configuration->decorate(
                    sprintf("You sell %s.\n", item->query("name")),
                    "message", "shop", colorConfiguration));
                store->storeItem(item);
                destruct(item);
            }
        }
    }
    if (money)
    {
        user->addMoney(money);
        tell_object(user, configuration->decorate(
            sprintf("You received $%d for your sold items.\n", money),
            "accounting", "shop", colorConfiguration)); 
    }
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
private string generateItemSummary(mapping summary, string colorConfiguration)
{
    string ret = "";

    if (!summary["identified"])
    {
        ret = configuration->decorate("This item has not been identified",
            "unidentified", "shop", colorConfiguration);
    }
    else if (member(summary, "No data"))
    {
        ret = configuration->decorate("View description for summary",
            "field", "shop", colorConfiguration);
    }
    else if (sizeof(summary))
    {
        string *output = ({});
        foreach(string key in (m_indices(summary) - ({"identified", "No data"})))
        {
            output += ({
                configuration->decorate(sprintf("%s: ", key), 
                    "field", "shop", colorConfiguration) +
                configuration->decorate(sprintf("%2d", summary[key]), 
                    "value", "shop", colorConfiguration)
            });
        }
        ret = implode(output, ", ");
    }
    return "    " + ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getBuyItemDetailsForType(object user, object store, 
    string type, string subtype)
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

        string colorConfiguration = user->colorConfiguration();
        object materials = load_object("/lib/dictionaries/materialsDictionary.c");

        foreach(string item in itemList)
        {
            string valueStr = configuration->decorate(
                sprintf("You can buy this item for %d.",
                    inventory[item]["value"]), "message", "shop",
                colorConfiguration);

            string qualityFormat = materialQualityFormatter(
                inventory[item]["quality"], colorConfiguration);

            ret[to_string(menuItem)] = ([
                "name" : sprintf(qualityFormat,
                    ((sizeof(inventory[item]["name"]) <= 20) ? inventory[item]["name"] :
                        inventory[item]["name"][0..16] + "...")) +
                    configuration->decorate(sprintf(" %8d", inventory[item]["value"]),
                        "cost", "shop", colorConfiguration),
                "description": inventory[item]["description"] + valueStr,
                "data": inventory[item]["data"],
                "value": inventory[item]["value"],
                "summary": generateItemSummary(inventory[item]["summary"],
                    colorConfiguration),
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
            tell_object(user, configuration->decorate(
                sprintf("You purchased %s for $%d.\n", itemObj->query("name"),
                    item["value"]), "message", "shop",
                user->colorConfiguration()));
        }
        else
        {
            tell_object(user, configuration->decorate("You do not have the "
                "funds for that.\n", "message", "shop",
                user->colorConfiguration()));
        }
    }
}

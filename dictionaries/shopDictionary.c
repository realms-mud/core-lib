//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#include "/lib/include/itemFormatters.h"

/////////////////////////////////////////////////////////////////////////////
public nomask string *getItemTypes(object user)
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
public nomask varargs int valueModifier(object user, object item, int selling)
{
    int ret = item->query("value");

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

    ret = to_int(ret * multiplier);
    return (!selling || (ret < 25000)) ? ret : 25000;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getItemDetailsForType(object user, string type, object store)
{
    mapping ret = ([]);
    int menuItem = 1;

    object *items = filter_array(deep_inventory(user) -
        user->registeredInventoryObjects(),
        (: (($1->query("type") == $2) && !$3->isModifierItem($1)) :), 
        type, user);

    object materials = load_object("/lib/dictionaries/materialsDictionary.c");
    if (sizeof(items))
    {
        foreach(object item in items)
        {
            int value = valueModifier(user, item, 1);
            string valueStr = value ?
                sprintf("[0;32mYou can sell this item for %d.[0m\n", value) :
                "[0;32mThis item has no value to the merchant.[0m\n";

            string name = item->query("name") + "    ";
            ret[to_string(menuItem)] = ([
                "name": sprintf(materials->getMaterialQualityFormatter(item),
                    ((sizeof(name) > 20) ? name[0..16] + "..." : name)),
                "identified": item->query("identified"),
                "object list": ({ item }),
                "description": item->long() + valueStr,
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
            "name": "Sell all" + 
                ((member(({ "armor", "weapon", "instrument" }), type) > -1) ?
                    " unequipped" : ""),
            "description": "This option will sell all of your unequipped " + type,
            "object list": filter_array(items, 
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
                money += valueModifier(user, item, 1);
                tell_object(user, sprintf("[0;32mYou sell %s.[0m\n",
                    item->query("name")));
                store->storeItem(item);
                destruct(item);
            }
        }
    }
    tell_object(user, sprintf("[0;37mYou received $%d for your sold items.[0m\n",
        money));
}
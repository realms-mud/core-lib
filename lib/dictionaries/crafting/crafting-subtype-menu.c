//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef _crafting_subtype_c
#define _crafting_subtype_c

#include "/lib/dictionaries/crafting/blueprints.c"

/////////////////////////////////////////////////////////////////////////////
private nomask string *getEquipmentBySubType(string type, string subType)
{
    mapping items = getBlueprintsByType(type);
    string *indices = m_indices(items);

    return sort_array(filter(indices,
        (: $3[$1]["subtype"] == $2 :), subType, items),
        (: $1 > $2 :));
}

/////////////////////////////////////////////////////////////////////////////
private nomask string getSubType(string subType)
{
    string ret = regreplace(subType, " ", "-");
    ret = regreplace(ret, "(s|ch|sh|x|z|dg|o)$", "\\1e");
    ret = regreplace(ret, "([^aeiou])y$", "\\1ie");
    ret += "s";
    ret = regreplace(ret, "(.*ing|.*armor|.*thrown)s$", "\\1");
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getCraftingListBySubType(string type, string subType,
    object user)
{
    mapping ret = ([]);
    string *itemSubtypes = getEquipmentBySubType(type, subType);

    int menuItem = 1;
    if (sizeof(itemSubtypes))
    {
        foreach(string item in itemSubtypes)
        {
            object blueprintObj = getBlueprintItem(type, item);

            int prereqsMet = prerequisitesMet(blueprintObj, user);
            int materialsMet = materialsAvailable(blueprintObj, user);
            string nameDesc = (sizeof(item) < 21) ? item :
                (item[0..16] + "...");
            ret[to_string(menuItem)] = ([
                "name": capitalize(nameDesc),
                "description": sprintf("This option lets you craft: %s\n%s\n", 
                    item, getDescriptionDetails(blueprintObj)),
                "selector": item,
                "type": type,
                "sub type": getSubType(subType),
                "canShow": prereqsMet && materialsMet,
                "prerequisites met": prereqsMet,
                "have materials": materialsMet,
                "show materials": 1,
                "do not format": 1
            ]);
            menuItem++;
        }
    }
    return ret;
}

#endif

//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef _craft_item_menu_c
#define _craft_item_menu_c

#include "/lib/services/crafting/blueprints.c"

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getCraftingDataForItem(string type, string item, object user)
{
    mapping ret = ([]);
    mapping blueprints = getBlueprintsByType(type);

    if (sizeof(blueprints) && member(blueprints, item))
    {
        string *itemSubtypes = sort_array(
            m_indices(blueprints[item]["crafting materials"]), (: $1 > $2 :));

        int menuItem = 1;
        if (sizeof(itemSubtypes))
        {
            foreach(string subType in itemSubtypes)
            {
                int isMaterial = 
                    !mappingp(blueprints[item]["crafting materials"][subType]);

                ret[to_string(menuItem)] = ([
                    "name": sprintf("Select %s", capitalize(subType)),
                    "description": sprintf("This option lets you craft the %s for your %s\n", 
                        subType, item),
                    "type": subType,
                    "details": blueprints[item]["crafting materials"][subType],
                    "selector": (isMaterial ? "material" : "component"),
                ]);
                menuItem++;
            }
        }
    }

    return ret;
}

#endif

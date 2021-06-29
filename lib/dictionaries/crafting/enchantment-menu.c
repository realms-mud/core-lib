//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef _enchantment_menu_c
#define _enchantment_menu_c

#include "/lib/dictionaries/crafting/blueprints.c"

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getEnchantmentTypes()
{
    mapping ret = ([]);

    int menuItem = 1;
    string *enchantmentTypes = sort_array(enchantmentClasses, (: $1 > $2 :));
    foreach(string enchantmentType in enchantmentTypes)
    {
        ret[to_string(menuItem)] = ([
            "name": capitalize(enchantmentType),
            "type": enchantmentType,
            "description": sprintf("This option lets you craft using: %s\n",
                enchantmentType),
            "canShow": 1
        ]);
        menuItem++;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getEnchantmentsOfType(string type, object user,
    object craftingItem)
{
    mapping ret = ([]);
    string *enchantmentsOfType = sort_array(
        filter(m_indices(equipmentEnchantments),
        (: (equipmentEnchantments[$1]["class"] == $2) :), type),
        (: $1 > $2 :));

    if (sizeof(enchantmentsOfType))
    {
        int menuItem = 1;
        foreach(string enchantment in enchantmentsOfType)
        {
            int hasMaterials = 1;

            object blueprintObj = getBlueprintItem("enchantments", enchantment);
            int prerequisites = prerequisitesMet(blueprintObj, user);

            string nameDesc = (sizeof(enchantment) < 21) ? enchantment :
                (enchantment[0..16] + "...");

            ret[to_string(menuItem)] = ([
                "name": capitalize(nameDesc),
                "type": enchantment,
                "description" : sprintf("This option lets you craft using: %s\n%s\n",
                    enchantment, getDictionary("materials")->getEquipmentStatistics(craftingItem)),
                "has materials" : hasMaterials,
                "prerequisites met" : prerequisites,
                "canShow" : (hasMaterials && prerequisites)
            ]);
            menuItem++;
        }
    }

    return ret;
}

#endif

//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#include "/lib/dictionaries/crafting/core.c"
#include "/lib/dictionaries/crafting/blueprints.c"
#include "/lib/dictionaries/crafting/component-menu.c"
#include "/lib/dictionaries/crafting/crafting-list-menu.c"
#include "/lib/dictionaries/crafting/crafting-subtype-menu.c"
#include "/lib/dictionaries/crafting/craft-item.c"
#include "/lib/dictionaries/crafting/craft-item-menu.c"
#include "/lib/dictionaries/crafting/enchantment-menu.c"
#include "/lib/dictionaries/crafting/enchantments.c"
#include "/lib/dictionaries/crafting/equipment-materials.c"
#include "/lib/dictionaries/crafting/generate-item.c"
#include "/lib/dictionaries/crafting/materials.c"
#include "/lib/dictionaries/crafting/materials-menu.c"
#include "/lib/dictionaries/crafting/top-level-menu.c"

/////////////////////////////////////////////////////////////////////////////
public nomask int isValidType(mixed type)
{
    int ret = 0;

    string *types = weaponSubTypes + armorCategories;
    if (stringp(type))
    {
        ret = member(types, type) > -1;
    }
    else if (pointerp(type) && sizeof(type))
    {
        ret = 1;
        foreach(string key in type)
        {
            ret &&= member(types, key) > -1;
        }
    }
    return ret;
}

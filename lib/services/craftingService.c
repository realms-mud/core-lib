//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#include "/lib/services/crafting/core.c"
#include "/lib/services/crafting/blueprints.c"
#include "/lib/services/crafting/component-menu.c"
#include "/lib/services/crafting/crafting-list-menu.c"
#include "/lib/services/crafting/crafting-subtype-menu.c"
#include "/lib/services/crafting/craft-item.c"
#include "/lib/services/crafting/craft-item-menu.c"
#include "/lib/services/crafting/enchantment-menu.c"
#include "/lib/services/crafting/enchantments.c"
#include "/lib/services/crafting/equipment-materials.c"
#include "/lib/services/crafting/generate-item.c"
#include "/lib/services/crafting/materials.c"
#include "/lib/services/crafting/materials-menu.c"
#include "/lib/services/crafting/top-level-menu.c"

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

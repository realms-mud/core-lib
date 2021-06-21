//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/dictionaries/crafting/core.c";
virtual inherit "/lib/dictionaries/crafting/blueprints.c";
virtual inherit "/lib/dictionaries/crafting/component-menu.c";
virtual inherit "/lib/dictionaries/crafting/crafting-list-menu.c";
virtual inherit "/lib/dictionaries/crafting/crafting-subtype-menu.c";
virtual inherit "/lib/dictionaries/crafting/craft-item.c";
virtual inherit "/lib/dictionaries/crafting/craft-item-menu.c";
virtual inherit "/lib/dictionaries/crafting/enchantment-menu.c";
virtual inherit "/lib/dictionaries/crafting/enchantments.c";
virtual inherit "/lib/dictionaries/crafting/equipment-materials.c";
virtual inherit "/lib/dictionaries/crafting/generate-item.c";
virtual inherit "/lib/dictionaries/crafting/materials.c";
virtual inherit "/lib/dictionaries/crafting/materials-menu.c";
virtual inherit "/lib/dictionaries/crafting/top-level-menu.c";

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

//*****************************************************************************
// Class: materialsDictionary
// File Name: materialsDictionary.c
//
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//
//*****************************************************************************
#include "/lib/dictionaries/materials/components/core.c"
#include "/lib/dictionaries/materials/components/armor-statistics.c"
#include "/lib/dictionaries/materials/components/blueprints.c"
#include "/lib/dictionaries/materials/components/combat-properties.c"
#include "/lib/dictionaries/materials/components/enchantments.c"
#include "/lib/dictionaries/materials/components/general-properties.c"
#include "/lib/dictionaries/materials/components/generate-component.c"
#include "/lib/dictionaries/materials/components/generate-random-item.c"
#include "/lib/dictionaries/materials/components/item-statistics.c"
#include "/lib/dictionaries/materials/components/locations.c"
#include "/lib/dictionaries/materials/components/random-material.c"
#include "/lib/dictionaries/materials/components/weapon-statistics.c"

/////////////////////////////////////////////////////////////////////////////
public string *getTypes(string type, object user)
{
    string *types = ({ type });
    if ((type == "metal") && user->isResearched("/lib/instances/research/crafting/materials/useCrystalsAsMetal.c"))
    {
        types += ({ "crystal" });
    }
    else if (type == "stone")
    {
        if (user->isResearched("/lib/instances/research/crafting/materials/useCrystalsAsStone.c"))
        {
            types += ({ "crystal" });
        }

        if (user->isResearched("/lib/instances/research/crafting/materials/useClaysAsStone.c"))
        {
            types += ({ "clay" });
        }
    }

    return types;
}

//*****************************************************************************
// Class: materialsService
// File Name: materialsService.c
//
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//
//*****************************************************************************
#include "/lib/services/materials/components/core.c"
#include "/lib/services/materials/components/armor-statistics.c"
#include "/lib/services/materials/components/blueprints.c"
#include "/lib/services/materials/components/combat-properties.c"
#include "/lib/services/materials/components/enchantments.c"
#include "/lib/services/materials/components/general-properties.c"
#include "/lib/services/materials/components/generate-component.c"
#include "/lib/services/materials/components/generate-random-item.c"
#include "/lib/services/materials/components/item-statistics.c"
#include "/lib/services/materials/components/locations.c"
#include "/lib/services/materials/components/random-material.c"
#include "/lib/services/materials/components/weapon-statistics.c"

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

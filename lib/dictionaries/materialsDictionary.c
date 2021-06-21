//*****************************************************************************
// Class: materialsDictionary
// File Name: materialsDictionary.c
//
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//
//*****************************************************************************
virtual inherit "/lib/dictionaries/materials/components/core.c";
virtual inherit "/lib/dictionaries/materials/components/armor-statistics.c";
virtual inherit "/lib/dictionaries/materials/components/blueprints.c";
virtual inherit "/lib/dictionaries/materials/components/combat-properties.c";
virtual inherit "/lib/dictionaries/materials/components/enchantments.c";
virtual inherit "/lib/dictionaries/materials/components/general-properties.c";
virtual inherit "/lib/dictionaries/materials/components/generate-component.c";
virtual inherit "/lib/dictionaries/materials/components/generate-random-item.c";
virtual inherit "/lib/dictionaries/materials/components/item-statistics.c";
virtual inherit "/lib/dictionaries/materials/components/locations.c";
virtual inherit "/lib/dictionaries/materials/components/random-material.c";
virtual inherit "/lib/dictionaries/materials/components/weapon-statistics.c";

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

//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    setShortDescription("A paved block along the west avenue");
    addObject("/areas/eledhel/central-city/characters/lamp-oil-seller.c");

    addExit("west", "/areas/eledhel/central-city/5x5.c");
    addExit("east", "/areas/eledhel/central-city/7x5.c");
}

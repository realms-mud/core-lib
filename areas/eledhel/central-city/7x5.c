//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    setShortDescription("The west avenue passes the older residences");
    addObject("/areas/eledhel/central-city/characters/ledger-clerk.c");

    addExit("west", "/areas/eledhel/central-city/6x5.c");
    addExit("east", "/areas/eledhel/central-city/8x5.c");
}

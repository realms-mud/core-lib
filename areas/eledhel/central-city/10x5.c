//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    setShortDescription("The west avenue nears the Aegis quarter");
    addObject("/areas/eledhel/central-city/characters/avenue-watch.c");

    addExit("west", "/areas/eledhel/central-city/9x5.c");
    addExit("east", "/areas/eledhel/central-city/11x5.c");
}

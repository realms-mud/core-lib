//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    setShortDescription("The east lane continues between old stone buildings");
    addObject("/areas/eledhel/central-city/characters/ward-guard.c");

    addExit("west", "/areas/eledhel/central-city/15x2.c");
    addExit("east", "/areas/eledhel/central-city/17x2.c");
}

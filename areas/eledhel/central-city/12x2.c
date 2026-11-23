//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    setShortDescription("A side street connecting the theater block to the plaza");
    addObject("/areas/eledhel/central-city/characters/stage-carpenter.c");

    addExit("east", "/areas/eledhel/central-city/13x2.c");
    addExit("north", "/areas/eledhel/central-city/12x3.c");
    addExit("south", "/areas/eledhel/central-city/12x1.c");
}

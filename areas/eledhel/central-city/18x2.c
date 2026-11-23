//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    setShortDescription("A long block of houses along the east lane");
    addObject("/areas/eledhel/central-city/characters/east-lane-watch.c");

    addExit("west", "/areas/eledhel/central-city/17x2.c");
    addExit("east", "/areas/eledhel/central-city/19x2.c");
}

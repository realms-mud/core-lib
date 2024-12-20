//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");

    addExit("east", "/areas/eledhel/southern-city/17x5.c");
    addExit("west", "/areas/eledhel/southern-city/15x5.c");
    addExit("south", "/areas/eledhel/southern-city/16x4.c");
}

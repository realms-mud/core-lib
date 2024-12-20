//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/pier.c");
    addFeature("/lib/environment/features/water/ocean.c", "east");
    addFeature("/lib/environment/features/water/ocean.c", "south");

    addDecorator("dock");
    addExit("west", "/areas/eledhel/southern-city/20x2.c");
    addExit("east", "/areas/eledhel/southern-city/22x2.c");
}

//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/pier.c");
    addFeature("/lib/environment/features/water/ocean.c", "east");
    addFeature("/lib/environment/features/water/ocean.c", "south");
    addFeature("/lib/environment/features/water/ocean.c", "north");

    addDecorator("dock end");
    addExit("west", "/areas/eledhel/southern-city/23x4.c");
}

//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
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
    addExit("west", "/areas/eledhel/southern-city/21x2.c");
    addExit("east", "/areas/eledhel/southern-city/23x2.c");
}

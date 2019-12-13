//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/pier.c");
    addFeature("/lib/environment/features/water/rocky-ocean-shore.c", "south");
    addFeature("/lib/environment/features/water/rocky-ocean-shore.c", "north");

    addDecorator("dock");
    addExit("west", "/lib/tutorial/eledhel/southern-city/19x2.c");
    addExit("east", "/lib/tutorial/eledhel/southern-city/21x2.c");
}

//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");

    addExit("north", "/lib/tutorial/eledhel/southern-city/12x0.c");
    addFeature("/lib/environment/features/paths/road.c", "north");

    addExit("south", "/lib/tutorial/eledhel/southern-rural/3x8.c");
    addFeature("/lib/environment/features/paths/road.c", "south");
    addExit("east", "/lib/tutorial/eledhel/southern-rural/4x9.c");
    addFeature("/lib/environment/features/paths/road.c", "east");
}

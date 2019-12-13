//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");

    addExit("north", "/lib/tutorial/eledhel/southwest-rural-one/16x1.c");
    addFeature("/lib/environment/features/paths/road.c", "north");
    addExit("east", "/lib/tutorial/eledhel/southwest-rural-one/17x0.c");
    addFeature("/lib/environment/features/paths/road.c", "east");
    addExit("west", "/lib/tutorial/eledhel/southwest-rural-one/15x0.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}


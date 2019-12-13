//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");

    addExit("south", "/lib/tutorial/eledhel/southwest-rural-one/5x2.c");
    addFeature("/lib/environment/features/paths/road.c", "south");
    addExit("east", "/lib/tutorial/eledhel/southwest-rural-one/6x3.c");
    addFeature("/lib/environment/features/paths/road.c", "east");
    addExit("west", "/lib/tutorial/eledhel/southwest-rural-one/4x3.c");
    addFeature("/lib/environment/features/paths/road.c", "west");
}


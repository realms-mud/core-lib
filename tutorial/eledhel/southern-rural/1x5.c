//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");

    addExit("north", "/lib/tutorial/eledhel/southern-rural/1x6.c");
    addFeature("/lib/environment/features/paths/road.c", "north");
    addExit("east", "/lib/tutorial/eledhel/southern-rural/2x5.c");
    addFeature("/lib/environment/features/paths/road.c", "east");
}


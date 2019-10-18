//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");

    addExit("east", "/lib/tutorial/eledhel/southern-rural/2x0.c");
    addFeature("/lib/environment/features/paths/road.c", "east");
    addExit("west", "/lib/tutorial/eledhel/southern-rural/0x0.c");
    addFeature("/lib/environment/features/paths/road.c", "west");
}


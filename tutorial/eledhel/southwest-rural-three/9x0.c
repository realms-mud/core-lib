//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");

    addExit("west", "/lib/tutorial/eledhel/southwest-rural-three/8x0.c");
    addFeature("/lib/environment/features/paths/road.c", "west");
    addExit("north", "/lib/tutorial/eledhel/southwest-rural-three/9x1.c");
    addFeature("/lib/environment/features/paths/road.c", "north");
}


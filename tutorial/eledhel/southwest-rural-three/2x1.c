//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");

    addExit("south", "/lib/tutorial/eledhel/southwest-rural-three/2x0.c");
    addFeature("/lib/environment/features/paths/road.c", "south");
    addExit("north", "/lib/tutorial/eledhel/southwest-rural-three/2x2.c");
    addFeature("/lib/environment/features/paths/road.c", "north");
}


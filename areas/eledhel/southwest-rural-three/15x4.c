//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");

    addExit("south", "/areas/eledhel/southwest-rural-three/15x3.c");
    addFeature("/lib/environment/features/paths/road.c", "south");
    addExit("east", "/areas/eledhel/southwest-rural-three/16x4.c");
    addFeature("/lib/environment/features/paths/road.c", "east");
}


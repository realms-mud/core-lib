//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");

    addExit("west", "/areas/eledhel/southwest-rural-three/1x4.c");
    addFeature("/lib/environment/features/paths/road.c", "west");
    addExit("east", "/areas/eledhel/southwest-rural-three/3x4.c");
    addFeature("/lib/environment/features/paths/road.c", "east");
}


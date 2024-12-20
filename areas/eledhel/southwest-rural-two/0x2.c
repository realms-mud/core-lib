//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");

    addExit("east", "/areas/eledhel/southwest-rural-two/1x2.c");
    addFeature("/lib/environment/features/paths/road.c", "east");

    addExit("west", "/areas/eledhel/southwest-rural-three/24x0.c");
    addFeature("/lib/environment/features/paths/road.c", "west");
}

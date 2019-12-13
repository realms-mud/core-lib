//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");

    addExit("west", "/lib/tutorial/eledhel/southwest-rural-three/22x0.c");
    addFeature("/lib/environment/features/paths/road.c", "west");
    addExit("east", "/lib/tutorial/eledhel/southwest-rural-three/24x0.c");
    addFeature("/lib/environment/features/paths/road.c", "east");
}


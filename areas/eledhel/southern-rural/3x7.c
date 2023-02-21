//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");

    addExit("north", "/areas/eledhel/southern-rural/3x8.c");
    addFeature("/lib/environment/features/paths/road.c", "north");
    addExit("west", "/areas/eledhel/southern-rural/2x7.c");
    addFeature("/lib/environment/features/paths/road.c", "west");
    addExit("east", "/areas/eledhel/southern-rural/4x7.c");
    addFeature("/lib/environment/features/paths/road.c", "east");
}


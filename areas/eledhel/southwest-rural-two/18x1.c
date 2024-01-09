//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-clearing.c");

    addExit("north", "/areas/eledhel/southwest-rural-two/18x2.c");
    addFeature("/lib/environment/features/paths/road.c", "north");
    addExit("east", "/areas/eledhel/southwest-rural-two/19x1.c");
    addFeature("/lib/environment/features/paths/road.c", "east");
    addExit("west", "/areas/eledhel/southwest-rural-two/17x1.c");
    addFeature("/lib/environment/features/paths/road.c", "west");
}

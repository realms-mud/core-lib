//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");

    addExit("south", "/areas/eledhel/southwest-rural-one/16x0.c");
    addFeature("/lib/environment/features/paths/road.c", "south");
    addExit("west", "/areas/eledhel/southwest-rural-one/15x1.c");
    addFeature("/lib/environment/features/paths/road.c", "west");
    addExit("north", "/areas/eledhel/southwest-rural-one/16x2.c");
    addFeature("/lib/environment/features/paths/road.c", "north");
}

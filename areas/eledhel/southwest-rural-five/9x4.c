//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/plains.c");
    setShortDescription("A cross-track serves the sheep folds and wool shed");
    addDecorator("village road intersection");
    addFeature("/lib/environment/features/paths/road.c", "west");
    addFeature("/lib/environment/features/paths/road.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("west", "/areas/eledhel/southwest-rural-five/8x4.c");
    addExit("east", "/areas/eledhel/southwest-rural-five/10x4.c");
    addExit("north", "/areas/eledhel/southwest-rural-five/9x3.c");
    addExit("south", "/areas/eledhel/southwest-rural-five/9x5.c");
}

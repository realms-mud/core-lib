//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-clearing.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/paths/dirt-road.c", "south");
    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addFeature("/lib/environment/features/trees/alder-stand.c", "north");
    addFeature("/lib/environment/features/water/stream.c", "southwest");

    addDecorator("village road T-south");

    addExit("east", "/areas/northern-road/north-gate/7x4.c");
    addExit("south", "/areas/northern-road/north-gate/6x5.c");
    addExit("west", "/areas/northern-road/north-gate/5x4.c");
}

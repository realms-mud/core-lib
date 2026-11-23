//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-clearing.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "north");
    addFeature("/lib/environment/features/paths/dirt-road.c", "south");
    addFeature("/lib/environment/features/paths/dirt-road.c", "east");

    addDecorator("village road T-east");

    addExit("north", "/areas/northern-road/north-gate/9x4.c");
    addExit("south", "/areas/northern-road/north-gate/9x6.c");
    addExit("east", "/areas/northern-road/north-gate/10x5.c");
}

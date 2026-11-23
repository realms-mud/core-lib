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

    addDecorator("village north-south road");

    addExit("north", "/areas/eledhel/estates/belectar/approach/8x0.c");
    addExit("south", "/areas/eledhel/estates/belectar/approach/8x2.c");
}

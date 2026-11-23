//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "north");
    addFeature("/lib/environment/features/paths/dirt-road.c", "south");

    addDecorator("village north-south road");

    addExit("north", "/areas/eledhel/estates/belectar/approach/0x2.c");
    addExit("south", "/areas/eledhel/estates/belectar/approach/0x4.c");
}

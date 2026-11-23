//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    setShortDescription("The old stone bridge crosses the Dhorlen stream");
    addDecorator("village north-south road");
    addFeature("/lib/environment/features/water/river-with-bridge.c");
    addFeature("/lib/environment/features/paths/road.c", "north");
    addFeature("/lib/environment/features/paths/road.c", "south");
    addExit("north", "/areas/eledhel/dhorlen/3x2.c");
    addExit("south", "/areas/eledhel/dhorlen/3x4.c");
}

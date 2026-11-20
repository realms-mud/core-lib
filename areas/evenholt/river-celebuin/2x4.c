//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail east-west");
    setShortDescription("The gravel bar at the inside bend");
    addFeature("/lib/environment/features/water/river.c", "north");
    addFeature("/lib/environment/features/landforms/ridge.c", "south");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("west", "/areas/evenholt/river-celebuin/1x4.c");
    addExit("east", "/areas/evenholt/river-celebuin/3x4.c");
    addRandomCreature(({ "otter", "mink", "muskrat" }));
}

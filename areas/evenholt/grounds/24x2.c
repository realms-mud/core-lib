//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail intersection");
    setShortDescription("The boiling pool beneath the cave fall");
    addFeature("/lib/environment/features/water/ravine-pond.c", "east");
    addFeature("/lib/environment/features/landforms/crag.c", "south");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("north", "/areas/evenholt/grounds/24x1.c");
    addExit("south", "/areas/evenholt/grounds/24x3.c");
    addExit("west", "/areas/evenholt/limestone-caves/4x0.c");
    addExit("east", "/areas/evenholt/river-celebuin/0x4.c");
    addRandomCreature(({ "otter", "muskrat" }));
}

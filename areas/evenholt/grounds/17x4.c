//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail T-south");
    setShortDescription("The first ridge lookout");
    addFeature("/lib/environment/features/landforms/ridge.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("west", "/areas/evenholt/grounds/16x4.c");
    addExit("east", "/areas/evenholt/grounds/18x4.c");
    addExit("south", "/areas/evenholt/grounds/17x5.c");
}

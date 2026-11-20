//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail T-north");
    setShortDescription("The narrow southern end of the ravine");
    addFeature("/lib/environment/features/water/creek.c", "south");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("north", "/areas/evenholt/river-celebuin/16x7.c");
    addExit("west", "/areas/evenholt/river-celebuin/15x8.c");
    addExit("east", "/areas/evenholt/river-celebuin/17x8.c");
}

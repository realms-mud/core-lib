//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail T-west");
    setShortDescription("The eastern spur of the lower ravine");
    addFeature("/lib/environment/features/trees/scots-pine-stand.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("north", "/areas/evenholt/river-celebuin/17x6.c");
    addExit("west", "/areas/evenholt/river-celebuin/16x7.c");
    addExit("south", "/areas/evenholt/river-celebuin/17x8.c");
}

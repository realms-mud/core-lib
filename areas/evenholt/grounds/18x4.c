//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail T-south");
    setShortDescription("The shadowed side of the pass");
    addFeature("/lib/environment/features/trees/pine-stand.c", "south");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("west", "/areas/evenholt/grounds/17x4.c");
    addExit("east", "/areas/evenholt/grounds/19x4.c");
    addExit("south", "/areas/evenholt/grounds/18x5.c");
}

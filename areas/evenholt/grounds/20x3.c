//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-clearing.c");
    addDecorator("forest trail T-north");
    setShortDescription("The hidden clearing");
    addFeature("/lib/environment/features/trees/paper-birch-stand.c", "north");
    addFeature("/lib/environment/features/trees/poplar-stand.c", "south");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("west", "/areas/evenholt/grounds/19x3.c");
    addExit("east", "/areas/evenholt/grounds/21x3.c");
    addExit("north", "/areas/evenholt/grounds/20x2.c");
}

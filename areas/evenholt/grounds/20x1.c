//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail intersection");
    setShortDescription("The game trail junction");
    addFeature("/lib/environment/features/trees/pine-stand.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("west", "/areas/evenholt/grounds/19x1.c");
    addExit("east", "/areas/evenholt/grounds/21x1.c");
    addExit("north", "/areas/evenholt/grounds/20x0.c");
    addExit("south", "/areas/evenholt/grounds/20x2.c");
}

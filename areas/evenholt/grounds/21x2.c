//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail T-west");
    setShortDescription("The stream-side end of the game trail");
    addFeature("/lib/environment/features/water/creek.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("north", "/areas/evenholt/grounds/21x1.c");
    addExit("south", "/areas/evenholt/grounds/21x3.c");
    addExit("west", "/areas/evenholt/grounds/20x2.c");
    addRandomCreature(({ "boar", "black bear", "red fox" }));
}

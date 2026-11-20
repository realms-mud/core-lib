//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail intersection");
    setShortDescription("The wargame woods below the ridge");
    addFeature("/lib/environment/features/landforms/hollow.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("north", "/areas/evenholt/grounds/20x1.c");
    addExit("south", "/areas/evenholt/grounds/20x3.c");
    addExit("east", "/areas/evenholt/grounds/21x2.c");
    addExit("west", "/areas/evenholt/grounds/19x2.c");
    addRandomCreature(({ "boar", "timber wolf", "white-tail deer" }));
}

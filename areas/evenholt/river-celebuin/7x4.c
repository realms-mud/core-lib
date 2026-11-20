//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail east-west");
    setShortDescription("The path where dry leaves hush the water");
    addFeature("/lib/environment/features/water/river.c", "south");
    addFeature("/lib/environment/features/trees/maple-stand.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("west", "/areas/evenholt/river-celebuin/6x4.c");
    addExit("east", "/areas/evenholt/river-celebuin/8x4.c");
    addRandomCreature(({ "raccoon", "red fox", "timber wolf" }));
}

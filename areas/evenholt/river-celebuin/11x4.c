//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail east-west");
    setShortDescription("The brush-screened cache below the rock");
    addFeature("/lib/environment/features/water/river.c", "south");
    addFeature("/lib/environment/features/plants/blackberry-bramble.c",
        "north");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addItem("/areas/evenholt/river-celebuin/items/map-chest.c", "north");
    addExit("west", "/areas/evenholt/river-celebuin/10x4.c");
    addExit("east", "/areas/evenholt/river-celebuin/12x4.c");
    addRandomCreature(({ "raccoon", "fisher", "outlaw" }));
}

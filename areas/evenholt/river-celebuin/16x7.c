//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail intersection");
    setShortDescription("The split in the southern ravine");
    addFeature("/lib/environment/features/landforms/hollow.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("north", "/areas/evenholt/river-celebuin/16x6.c");
    addExit("west", "/areas/evenholt/river-celebuin/15x7.c");
    addExit("east", "/areas/evenholt/river-celebuin/17x7.c");
    addExit("south", "/areas/evenholt/river-celebuin/16x8.c");
}

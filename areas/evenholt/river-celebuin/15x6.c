//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail T-east");
    setShortDescription("The pass that leaves the gorge to the northwest");
    addFeature("/lib/environment/features/landforms/ridge.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("north", "/areas/evenholt/river-celebuin/15x5.c");
    addExit("east", "/areas/evenholt/river-celebuin/16x6.c");
    addExit("south", "/areas/evenholt/river-celebuin/15x7.c");
}

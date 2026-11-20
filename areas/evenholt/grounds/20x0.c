//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-clearing.c");
    addDecorator("forest trail T-south");
    setShortDescription("Tinruth's wargame camp");
    addFeature("/lib/environment/features/trees/pine-stand.c", "north");
    addFeature("/lib/environment/features/landforms/hill.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addObject("/areas/evenholt/characters/tinruth.c");
    addExit("west", "/areas/evenholt/grounds/19x0.c");
    addExit("east", "/areas/evenholt/grounds/21x0.c");
    addExit("south", "/areas/evenholt/grounds/20x1.c");
    addExit("down", "/areas/evenholt/limestone-caves/0x0.c");
}

//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-clearing.c");
    addDecorator("forest trail intersection");
    setShortDescription("The archery ground by the creek");
    addFeature("/lib/environment/features/water/creek.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addObject("/areas/evenholt/characters/tinruth.c");
    addExit("west", "/areas/evenholt/grounds/20x3.c");
    addExit("east", "/areas/evenholt/grounds/22x3.c");
    addExit("north", "/areas/evenholt/grounds/21x2.c");
    addExit("south", "/areas/evenholt/grounds/21x4.c");
}

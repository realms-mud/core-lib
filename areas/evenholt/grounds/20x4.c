//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-clearing.c");
    addDecorator("forest trail intersection");
    setShortDescription("The front steps and yard");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addObject("/areas/evenholt/characters/aglaradan.c");
    addExit("west", "/areas/evenholt/grounds/19x4.c");
    addExit("east", "/areas/evenholt/grounds/21x4.c");
    addExit("north", "/areas/evenholt/manor/0x1.c");
    addExit("south", "/areas/evenholt/grounds/20x5.c");
}

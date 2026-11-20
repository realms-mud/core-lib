//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail T-east");
    setShortDescription("The shaded path behind the house");
    addFeature("/lib/environment/features/trees/poplar-stand.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("south", "/areas/evenholt/grounds/19x4.c");
    addExit("east", "/areas/evenholt/grounds/20x3.c");
    addExit("north", "/areas/evenholt/grounds/19x2.c");
}

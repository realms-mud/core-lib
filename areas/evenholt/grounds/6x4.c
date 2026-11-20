//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail T-north");
    setShortDescription("The path above the falls");
    addFeature("/lib/environment/features/water/ravine-waterfall.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("west", "/areas/evenholt/grounds/5x4.c");
    addExit("east", "/areas/evenholt/grounds/7x4.c");
    addExit("north", "/areas/evenholt/grounds/6x3.c");
}

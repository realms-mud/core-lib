//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail south-east");
    setShortDescription("The falls below the path");
    addFeature("/lib/environment/features/water/ravine-waterfall.c", "east");
    addFeature("/lib/environment/features/trees/maple-stand.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("south", "/areas/evenholt/grounds/6x4.c");
    addExit("east", "/areas/evenholt/grounds/7x3.c");
}

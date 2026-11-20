//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail south-west");
    setShortDescription("The waterfall pool");
    addFeature("/lib/environment/features/water/ravine-pond.c", "north");
    addFeature("/lib/environment/features/landforms/crag.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("west", "/areas/evenholt/grounds/6x3.c");
    addExit("south", "/areas/evenholt/grounds/7x4.c");
}

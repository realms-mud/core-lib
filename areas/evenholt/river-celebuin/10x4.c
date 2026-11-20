//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail east-west");
    setShortDescription("The cow's-head rock above the river");
    addFeature("/lib/environment/features/landforms/crag.c", "north");
    addFeature("/lib/environment/features/water/river.c", "south");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("west", "/areas/evenholt/river-celebuin/9x4.c");
    addExit("east", "/areas/evenholt/river-celebuin/11x4.c");
}

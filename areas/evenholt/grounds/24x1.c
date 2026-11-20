//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail north-south");
    setShortDescription("The steep riverbank track");
    addFeature("/lib/environment/features/landforms/crag.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("north", "/areas/evenholt/grounds/24x0.c");
    addExit("south", "/areas/evenholt/grounds/24x2.c");
}

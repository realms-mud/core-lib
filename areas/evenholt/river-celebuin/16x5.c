//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail T-south");
    setShortDescription("The gorge floor beneath both ridges");
    addFeature("/lib/environment/features/water/creek.c", "east");
    addFeature("/lib/environment/features/landforms/cliff.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("west", "/areas/evenholt/river-celebuin/15x5.c");
    addExit("east", "/areas/evenholt/river-celebuin/17x5.c");
    addExit("south", "/areas/evenholt/river-celebuin/16x6.c");
}

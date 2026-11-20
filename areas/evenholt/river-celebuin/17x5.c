//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail south-west");
    setShortDescription("The eastern wall of the gorge");
    addFeature("/lib/environment/features/landforms/cliff.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("west", "/areas/evenholt/river-celebuin/16x5.c");
    addExit("south", "/areas/evenholt/river-celebuin/17x6.c");
}

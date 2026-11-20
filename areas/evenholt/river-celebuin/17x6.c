//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail T-west");
    setShortDescription("The steep eastern archer's ledge");
    addFeature("/lib/environment/features/landforms/cliff.c", "east");
    addFeature("/lib/environment/features/trees/oak-stand.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("north", "/areas/evenholt/river-celebuin/17x5.c");
    addExit("west", "/areas/evenholt/river-celebuin/16x6.c");
    addExit("south", "/areas/evenholt/river-celebuin/17x7.c");
}

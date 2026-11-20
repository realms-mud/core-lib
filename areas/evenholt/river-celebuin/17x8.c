//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail north-west");
    setShortDescription("The ravine closes against the eastern cliff");
    addFeature("/lib/environment/features/landforms/cliff.c", "east");
    addFeature("/lib/environment/features/trees/oak-stand.c", "south");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("north", "/areas/evenholt/river-celebuin/17x7.c");
    addExit("west", "/areas/evenholt/river-celebuin/16x8.c");
}

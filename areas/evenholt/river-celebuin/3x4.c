//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail T-north");
    setShortDescription("The river trail forks through hardwoods");
    addFeature("/lib/environment/features/trees/oak-stand.c", "north");
    addFeature("/lib/environment/features/water/river.c", "south");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("west", "/areas/evenholt/river-celebuin/2x4.c");
    addExit("east", "/areas/evenholt/river-celebuin/4x4.c");
    addExit("north", "/areas/evenholt/river-celebuin/3x3.c");
}

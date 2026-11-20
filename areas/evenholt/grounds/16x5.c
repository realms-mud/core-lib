//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail north-east");
    setShortDescription("The first trees below the plateau");
    addFeature("/lib/environment/features/trees/oak-stand.c", "south");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("north", "/areas/evenholt/grounds/16x4.c");
    addExit("east", "/areas/evenholt/grounds/17x5.c");
}

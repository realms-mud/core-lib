//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail north-west");
    setShortDescription("The wooded flank below the yard");
    addFeature("/lib/environment/features/trees/ash-stand.c", "south");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("west", "/areas/evenholt/grounds/19x5.c");
    addExit("north", "/areas/evenholt/grounds/20x4.c");
}

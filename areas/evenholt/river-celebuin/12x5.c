//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail north-east");
    setShortDescription("The creek leading southeast from the river");
    addFeature("/lib/environment/features/water/creek.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("north", "/areas/evenholt/river-celebuin/12x4.c");
    addExit("east", "/areas/evenholt/river-celebuin/13x5.c");
}

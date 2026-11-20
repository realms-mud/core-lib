//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail south-west");
    setShortDescription("The river trail turns toward the gorge");
    addFeature("/lib/environment/features/water/river.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("west", "/areas/evenholt/river-celebuin/11x4.c");
    addExit("south", "/areas/evenholt/river-celebuin/12x5.c");
}

//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail T-north");
    setShortDescription("The hollow into the southeast pass");
    addFeature("/lib/environment/features/landforms/hollow.c", "south");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("west", "/areas/evenholt/grounds/18x5.c");
    addExit("north", "/areas/evenholt/grounds/19x4.c");
    addExit("east", "/areas/evenholt/grounds/20x5.c");
}

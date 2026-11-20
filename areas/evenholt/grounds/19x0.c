//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail east");
    setShortDescription("The northern camp's west lookout");
    addFeature("/lib/environment/features/landforms/ridge.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("east", "/areas/evenholt/grounds/20x0.c");
}

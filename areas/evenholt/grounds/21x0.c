//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail T-south");
    setShortDescription("The ballista post above the river");
    addFeature("/lib/environment/features/landforms/promontory.c", "east");
    addFeature("/lib/environment/features/trees/white-pine-stand.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addItem("/lib/environment/items/military/ballista.c", "north");
    addExit("west", "/areas/evenholt/grounds/20x0.c");
    addExit("east", "/areas/evenholt/grounds/22x0.c");
    addExit("south", "/areas/evenholt/grounds/21x1.c");
}

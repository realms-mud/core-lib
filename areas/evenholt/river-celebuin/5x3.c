//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail south-west");
    setShortDescription("The path descends to the broad ford");
    addFeature("/lib/environment/features/trees/poplar-stand.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("west", "/areas/evenholt/river-celebuin/4x3.c");
    addExit("south", "/areas/evenholt/river-celebuin/5x4.c");
    addRandomCreature(({ "boar", "red fox" }));
}

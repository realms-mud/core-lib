//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail south");
    setShortDescription("A bare lookout shelf above the trail");
    addFeature("/lib/environment/features/landforms/ridge.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addRandomCreature(({ "outlaw", "red fox" }));
    addExit("south", "/areas/eledhel/vargath-keep/approach/2x2.c");
}

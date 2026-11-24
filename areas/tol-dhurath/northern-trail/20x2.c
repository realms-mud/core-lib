//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-clearing.c");
    addFeature("/lib/environment/features/water/ravine-creek.c", "east");
    addFeature("/lib/environment/features/water/shallow-ford.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "south");

    addExit("south", "/areas/tol-dhurath/northern-trail/20x1.c");
    addExit("north", "/areas/tol-dhurath/northern-trail/20x3.c");

    addRandomCreature(({"beaver","otter","outlaw"}));
}

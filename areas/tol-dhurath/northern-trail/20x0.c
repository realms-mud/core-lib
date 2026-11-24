//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-clearing.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "south");

    addExit("north", "/areas/tol-dhurath/northern-trail/20x1.c");
    addExit("south", "/areas/tol-dhurath/forest-1/15x9.c");

    addRandomCreature(({"white-tail deer","outlaw","gray fox"}));
}

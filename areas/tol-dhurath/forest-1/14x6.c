//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-clearing.c");
    addFeature("/areas/tol-dhurath/features/standing-stones.c", "none");

    addExit("north", "/areas/tol-dhurath/forest-1/14x7.c");
    addFeature("/lib/environment/features/paths/path.c", "north");

    addRandomCreature(({"gray fox","red fox"}));
}

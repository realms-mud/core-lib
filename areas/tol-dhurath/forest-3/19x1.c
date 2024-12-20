//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/pond.c", "north");
    addFeature("/lib/environment/features/trees/crabapple-stand.c", "west");

    addExit("north", "/areas/tol-dhurath/forest-3/19x2.c");
    addFeature("/lib/environment/features/paths/path.c", "north");

    addRandomCreature(({"outlaw","red fox","boar"}));
}

//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/beech-stand.c", "north");

    addExit("north", "/areas/tol-dhurath/forest-3/16x9.c");
    addFeature("/lib/environment/features/paths/path.c", "north");

    addRandomCreature(({"coyote","outlaw"}));
}

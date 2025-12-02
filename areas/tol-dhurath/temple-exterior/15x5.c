//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/canyon-creek.c", "east");
    addFeature("/lib/environment/features/water/pond.c", "northwest");
    addFeature("/lib/environment/features/trees/magnolia-stand.c", "west");

    addExit("north", "/areas/tol-dhurath/temple-exterior/15x6.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("south", "/areas/tol-dhurath/temple-exterior/15x4.c");
    addFeature("/lib/environment/features/paths/path.c", "south");

    addRandomCreature(({"ruffian","coyote","outlaw","gray wolf"}));
}

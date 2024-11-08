//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/canyon-brook.c", "south");
    addFeature("/lib/environment/features/water/canyon-dry-bed.c", "north");
    addFeature("/lib/environment/features/water/ravine-creek.c", "southeast");

    addExit("south", "/areas/tol-dhurath/forest-3/8x0.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("east", "/areas/tol-dhurath/forest-3/9x1.c");
    addFeature("/lib/environment/features/paths/path.c", "east");

    addRandomCreature(({"ruffian","outlaw","coyote"}));
}

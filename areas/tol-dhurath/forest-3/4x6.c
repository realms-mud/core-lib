//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/canyon-dry-bed.c", "northwest");

    addExit("west", "/areas/tol-dhurath/forest-3/3x6.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("south", "/areas/tol-dhurath/forest-3/4x5.c");
    addFeature("/lib/environment/features/paths/path.c", "south");

    addRandomCreature(({"ruffian","coyote","black bear"}));
}

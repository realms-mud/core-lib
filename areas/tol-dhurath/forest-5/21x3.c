//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/brook.c", "north");
    addFeature("/lib/environment/features/water/canyon-dry-bed.c", "north");

    addExit("south", "/areas/tol-dhurath/forest-5/21x2.c");
    addFeature("/lib/environment/features/paths/path.c", "south");

    addRandomCreature(({"white-tail deer","gray fox","ruffian"}));
}

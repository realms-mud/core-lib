//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/hillock.c", "north");
    addFeature("/lib/environment/features/trees/ash-stand.c", "north");
    addFeature("/lib/environment/features/water/canyon-dry-bed.c", "north");

    addExit("east", "/areas/tol-dhurath/forest-5/16x3.c");
    addFeature("/lib/environment/features/paths/path.c", "east");

    addRandomCreature(({"gopher","coyote","white-tail deer","boar","badger","chipmunk"}));
}

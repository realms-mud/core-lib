//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-clearing.c");
    addFeature(
        "/areas/tol-dhurath/northern-trail/features/old-waystation.c",
        "north");
    addFeature("/lib/environment/features/paths/path.c", "north");

    addExit("west", "/areas/tol-dhurath/northern-trail/13x4.c");
    addExit("east", "/areas/tol-dhurath/northern-trail/15x4.c");
    addExit("north", "/areas/tol-dhurath/northern-trail/14x5.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "east");

    addRandomCreature(({"outlaw","white-tail deer","gray fox"}));
}

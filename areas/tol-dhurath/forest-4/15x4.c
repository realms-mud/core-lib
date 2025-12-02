//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/ravine-dry-creek.c", "east");
    addFeature("/lib/environment/features/landforms/knoll.c", "east");
    addFeature("/lib/environment/features/landforms/hollow.c", "east");

    addExit("east", "/areas/tol-dhurath/forest-4/16x4.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("west", "/areas/tol-dhurath/forest-4/14x4.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("north", "/areas/tol-dhurath/forest-4/15x5.c");
    addFeature("/lib/environment/features/paths/path.c", "north");

    addRandomCreature(({"zombie","ruffian","warg","opossum","chipmunk"}));
}

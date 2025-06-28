//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/knoll.c", "northwest");

    addExit("east", "/lib/tests/support/pathfinding/10x4.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("north", "/lib/tests/support/pathfinding/9x5.c");
    addFeature("/lib/environment/features/paths/path.c", "north");

    addRandomCreature(({"ruffian","opossum","coyote","chipmunk","badger"}));
}


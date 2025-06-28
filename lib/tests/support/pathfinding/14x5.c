//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/ambrosia-apple-stand.c", "south");
    addFeature("/lib/environment/features/landforms/hill.c", "south");

    addExit("north", "/lib/tests/support/pathfinding/14x6.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("east", "/lib/tests/support/pathfinding/15x5.c");
    addFeature("/lib/environment/features/paths/path.c", "east");

    addRandomCreature(({"ruffian","opossum","outlaw","porcupine","beaver","knight of the storm"}));
}


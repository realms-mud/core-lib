//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/glen.c", "north");
    addFeature("/lib/environment/features/landforms/hill.c", "north");

    addExit("north", "/lib/tests/support/pathfinding/10x4.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("south", "/lib/tests/support/pathfinding/10x2.c");
    addFeature("/lib/environment/features/paths/path.c", "south");

    addRandomCreature(({"kit fox","ruffian","keeper of the night","coyote","outlaw","white-tail deer"}));
}


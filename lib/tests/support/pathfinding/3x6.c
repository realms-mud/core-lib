//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/hollow.c", "south");

    addExit("west", "/lib/tests/support/pathfinding/2x6.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("east", "/lib/tests/support/pathfinding/4x6.c");
    addFeature("/lib/environment/features/paths/path.c", "east");

    addRandomCreature(({"ruffian","mule deer","outlaw","raccoon"}));
}


//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/elm-stand.c", "east");
    addFeature("/lib/environment/features/trees/dogwood-stand.c", "east");

    addExit("west", "/lib/tests/support/pathfinding/20x5.c");
    addFeature("/lib/environment/features/paths/path.c", "west");

    addRandomCreature(({"keeper of the night","groundhog","mink","gray squirrel"}));
}


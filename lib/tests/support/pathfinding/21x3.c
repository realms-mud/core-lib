//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/brook.c", "northeast");
    addFeature("/lib/environment/features/trees/pine-stand.c", "northeast");
    addFeature("/lib/environment/features/landforms/knoll.c", "northeast");

    addExit("east", "/lib/tests/support/pathfinding/22x3.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("south", "/lib/tests/support/pathfinding/21x2.c");
    addFeature("/lib/environment/features/paths/path.c", "south");

    addRandomCreature(({"outlaw","boar","black bear"}));
}


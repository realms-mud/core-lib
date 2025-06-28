//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/beech-stand.c", "north");

    addExit("east", "/lib/tests/support/pathfinding/5x5.c");
    addFeature("/lib/environment/features/paths/path.c", "east");

    addRandomCreature(({"skunk","opossum","outlaw","red squirrel","white-tail deer","weasel","otter"}));
}


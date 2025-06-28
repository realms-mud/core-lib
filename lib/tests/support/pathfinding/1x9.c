//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/poplar-stand.c", "northeast");
    addFeature("/lib/environment/features/water/brook.c", "northeast");
    addFeature("/lib/environment/features/landforms/knoll.c", "northeast");

    addExit("east", "/lib/tests/support/pathfinding/2x9.c");
    addFeature("/lib/environment/features/paths/path.c", "east");

    addRandomCreature(({"outlaw","ruffian"}));
}


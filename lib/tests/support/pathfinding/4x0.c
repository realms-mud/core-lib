//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/mound.c", "southwest");
    addFeature("/lib/environment/features/water/canyon-creek.c", "southwest");
    addFeature("/lib/environment/features/landforms/promontory.c", "southwest");

    addExit("east", "/lib/tests/support/pathfinding/5x0.c");
    addFeature("/lib/environment/features/paths/path.c", "east");

    addRandomCreature(({"hunter","keeper of the night","weasel"}));
}


//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/pine-stand.c", "north");
    addFeature("/lib/environment/features/landforms/hill.c", "north");

    addExit("west", "/lib/tests/support/pathfinding/23x4.c");
    addFeature("/lib/environment/features/paths/path.c", "west");

    addRandomCreature(({"hunter","ruffian","wolverine","otter","badger"}));
}


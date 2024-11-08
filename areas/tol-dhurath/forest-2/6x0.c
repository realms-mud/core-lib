//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/creek.c", "east");
    addFeature("/lib/environment/features/trees/spruce-stand.c", "north");

    addExit("west", "/areas/tol-dhurath/forest-2/5x0.c");
    addFeature("/lib/environment/features/paths/path.c", "west");

    addRandomCreature(({"white-tail deer","otter","hunter"}));
}

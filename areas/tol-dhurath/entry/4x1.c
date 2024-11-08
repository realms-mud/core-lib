//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/brook.c", "southwest");
    addFeature("/lib/environment/features/trees/bing-cherry-stand.c", "west");

    addExit("south", "/areas/tol-dhurath/entry/4x0.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("west", "/areas/tol-dhurath/entry/3x1.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("north", "/areas/tol-dhurath/entry/4x2.c");
    addFeature("/lib/environment/features/paths/path.c", "north");

    addRandomCreature(({"white-tail deer","gray fox","coyote"}));
}

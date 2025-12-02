//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/rocky-lake-shore.c", "north");
    addFeature("/lib/environment/features/trees/pine-stand.c", "west");

    addExit("east", "/areas/tol-dhurath/forest-3/12x4.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("west", "/areas/tol-dhurath/forest-3/10x4.c");
    addFeature("/lib/environment/features/paths/path.c", "west");

    addRandomCreature(({"gray fox","ruffian","hunter","coyote"}));
}

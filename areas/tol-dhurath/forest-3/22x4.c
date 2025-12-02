//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/beech-stand.c", "north");
    addFeature("/lib/environment/features/trees/oak-stand.c", "east");
    addFeature("/lib/environment/features/water/rocky-lake-shore.c", "west");

    addExit("north", "/areas/tol-dhurath/forest-3/22x5.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("south", "/areas/tol-dhurath/forest-3/22x3.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}

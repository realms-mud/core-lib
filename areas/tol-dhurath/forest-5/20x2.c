//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/hillock.c", "northeast");
    addFeature("/lib/environment/features/trees/oak-stand.c", "northeast");
    addFeature("/lib/environment/features/water/ravine-dry-creek.c", "northeast");

    addExit("south", "/areas/tol-dhurath/forest-5/20x1.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("west", "/areas/tol-dhurath/forest-5/19x2.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("east", "/areas/tol-dhurath/forest-5/21x2.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}

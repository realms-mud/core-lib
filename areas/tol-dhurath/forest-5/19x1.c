//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/beech-stand.c", "south");
    addFeature("/lib/environment/features/landforms/hummock.c", "south");
    addFeature("/lib/environment/features/trees/hemlock-stand.c", "south");

    addExit("north", "/areas/tol-dhurath/forest-5/19x2.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("west", "/areas/tol-dhurath/forest-5/18x1.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}

//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/birch-stand.c", "southeast");
    addFeature("/lib/environment/features/landforms/ridge.c", "south");

    addExit("north", "/areas/tol-dhurath/temple-exterior/20x3.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("west", "/areas/tol-dhurath/temple-exterior/19x2.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}

//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/ravine-dry-creek.c", "west");
    addFeature("/lib/environment/features/landforms/hummock.c", "south");
    addFeature("/lib/environment/features/landforms/butte.c", "southeast");

    addExit("south", "/areas/tol-dhurath/temple-exterior/11x2.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("north", "/areas/tol-dhurath/temple-exterior/11x4.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}

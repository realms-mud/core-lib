//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/knoll.c", "northwest");
    addFeature("/lib/environment/features/trees/cottonwood-stand.c", "northwest");
    addFeature("/lib/environment/features/trees/willow-stand.c", "northwest");

    addExit("north", "/areas/tol-dhurath/temple-exterior/3x0.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("south", "/areas/tol-dhurath/forest-5/3x8.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("west", "/areas/tol-dhurath/forest-5/2x9.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}

//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/golden-apple-stand.c", "north");
    addFeature("/lib/environment/features/landforms/sinkhole.c", "west");
    addFeature("/lib/environment/features/trees/spruce-stand.c", "east");

    addExit("west", "/areas/tol-dhurath/forest-3/20x2.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("north", "/areas/tol-dhurath/forest-3/21x3.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}

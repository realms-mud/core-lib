//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/knoll.c", "southwest");
    addFeature("/lib/environment/features/water/brook.c", "southwest");
    addFeature("/lib/environment/features/trees/walnut-stand.c", "southwest");

    addExit("north", "/areas/tol-dhurath/forest-5/13x6.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("east", "/areas/tol-dhurath/forest-5/14x5.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}

//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/vale.c", "northeast");
    addFeature("/lib/environment/features/trees/dogwood-stand.c", "northeast");
    addFeature("/lib/environment/features/water/canyon-dry-bed.c", "northeast");

    addExit("east", "/areas/tol-dhurath/forest-5/7x0.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("west", "/areas/tol-dhurath/forest-5/5x0.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}

//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/waterfall.c", "south");
    addFeature("/lib/environment/features/trees/cypress-stand.c", "west");
    addFeature("/lib/environment/features/water/brook.c", "northeast");

    addExit("south", "/areas/tol-dhurath/forest-2/4x0.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("east", "/areas/tol-dhurath/forest-2/5x1.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}

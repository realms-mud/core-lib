//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/creek.c", "west");
    addFeature("/lib/environment/features/trees/walnut-stand.c", "south");
    addFeature("/lib/environment/features/landforms/hill.c", "northeast");

    addExit("north", "/areas/tol-dhurath/forest-1/4x2.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("east", "/areas/tol-dhurath/forest-1/5x1.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}

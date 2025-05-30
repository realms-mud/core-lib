//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/oak-stand.c", "southeast");
    addFeature("/lib/environment/features/trees/aspen-stand.c", "west");
    addFeature("/lib/environment/features/landforms/ridge.c", "north");

    addExit("south", "/areas/tol-dhurath/forest-1/11x1.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("north", "/areas/tol-dhurath/forest-1/11x3.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}

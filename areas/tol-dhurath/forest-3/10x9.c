//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/poplar-stand.c", "southeast");
    addFeature("/lib/environment/features/landforms/hollow.c", "west");
    addFeature("/lib/environment/features/landforms/ridge.c", "north");

    addExit("east", "/areas/tol-dhurath/forest-3/11x9.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("west", "/areas/tol-dhurath/forest-3/9x9.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}

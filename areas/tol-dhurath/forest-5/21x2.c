//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/promontory.c", "northwest");
    addFeature("/lib/environment/features/landforms/ridge.c", "northwest");

    addExit("north", "/areas/tol-dhurath/forest-5/21x3.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("west", "/areas/tol-dhurath/forest-5/20x2.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}

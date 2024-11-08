//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/ravine-brook.c", "northeast");
    addFeature("/lib/environment/features/landforms/ridge.c", "northeast");
    addFeature("/lib/environment/features/water/brook.c", "northeast");

    addExit("west", "/areas/tol-dhurath/forest-4/20x3.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("east", "/areas/tol-dhurath/forest-4/22x3.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}

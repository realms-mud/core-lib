//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/hill.c", "northwest");
    addFeature("/lib/environment/features/trees/pine-stand.c", "northwest");

    addExit("east", "/areas/tol-dhurath/forest-5/19x7.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("south", "/areas/tol-dhurath/forest-5/18x6.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}

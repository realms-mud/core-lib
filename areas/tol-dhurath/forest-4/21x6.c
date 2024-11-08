//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/dell.c", "east");
    addFeature("/lib/environment/features/water/brook.c", "east");

    addExit("east", "/areas/tol-dhurath/forest-4/22x6.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("south", "/areas/tol-dhurath/forest-4/21x5.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}

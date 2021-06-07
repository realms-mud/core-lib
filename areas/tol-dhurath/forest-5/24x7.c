//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/hummock.c", "southwest");
    addFeature("/lib/environment/features/landforms/hill.c", "southwest");
    addFeature("/lib/environment/features/landforms/glen.c", "southwest");

    addExit("west", "/areas/tol-dhurath/forest-5/23x7.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("south", "/areas/tol-dhurath/forest-5/24x6.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}

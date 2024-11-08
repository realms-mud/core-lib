//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/aspen-stand.c", "north");
    addFeature("/lib/environment/features/landforms/hill.c", "north");

    addExit("south", "/areas/tol-dhurath/forest-5/21x7.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("west", "/areas/tol-dhurath/forest-5/20x8.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}

//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/dell.c", "west");
    addFeature("/lib/environment/features/landforms/glen.c", "southeast");
    addFeature("/lib/environment/features/water/gorge-creek.c", "east");

    addExit("west", "/areas/tol-dhurath/forest-3/20x6.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("east", "/areas/tol-dhurath/forest-3/22x6.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}

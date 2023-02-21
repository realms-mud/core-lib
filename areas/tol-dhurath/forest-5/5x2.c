//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/glen.c", "northeast");
    addFeature("/lib/environment/features/water/gorge-creek.c", "northeast");
    addFeature("/lib/environment/features/trees/maple-stand.c", "northeast");

    addExit("west", "/areas/tol-dhurath/forest-5/4x2.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("south", "/areas/tol-dhurath/forest-5/5x1.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}

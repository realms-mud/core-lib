//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/hill.c", "north");
    addFeature("/lib/environment/features/water/gorge-creek.c", "south");
    addFeature("/lib/environment/features/trees/sycamore-stand.c", "northwest");

    addExit("west", "/areas/tol-dhurath/temple-exterior/15x0.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("east", "/areas/tol-dhurath/temple-exterior/17x0.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}

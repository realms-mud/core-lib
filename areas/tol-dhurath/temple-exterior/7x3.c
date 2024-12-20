//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/willow-stand.c", "south");
    addFeature("/lib/environment/features/water/ravine-creek.c", "west");
    addFeature("/lib/environment/features/water/brook.c", "southwest");

    addExit("north", "/areas/tol-dhurath/temple-exterior/7x4.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("west", "/areas/tol-dhurath/temple-exterior/6x3.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}

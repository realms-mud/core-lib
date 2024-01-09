//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/ash-stand.c", "east");
    addFeature("/lib/environment/features/water/canyon-brook.c", "north");
    addFeature("/lib/environment/features/trees/maple-stand.c", "south");

    addExit("south", "/areas/tol-dhurath/temple-exterior/24x2.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("north", "/areas/tol-dhurath/temple-exterior/24x4.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}

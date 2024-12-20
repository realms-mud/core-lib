//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/knoll.c", "south");
    addFeature("/lib/environment/features/water/canyon-dry-bed.c", "east");
    addFeature("/lib/environment/features/water/stream.c", "north");

    addExit("south", "/areas/tol-dhurath/temple-exterior/24x0.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("north", "/areas/tol-dhurath/temple-exterior/24x2.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}

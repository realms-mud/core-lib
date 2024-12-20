//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/beech-stand.c", "south");
    addFeature("/lib/environment/features/trees/buckthorn-stand.c", "north");
    addFeature("/lib/environment/features/trees/cedar-stand.c", "east");

    addExit("west", "/areas/tol-dhurath/forest-3/10x0.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("east", "/areas/tol-dhurath/forest-3/12x0.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}

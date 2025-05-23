//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/ash-stand.c", "east");
    addFeature("/lib/environment/features/trees/golden-apple-stand.c", "west");

    addExit("south", "/areas/tol-dhurath/temple-exterior/3x0.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("east", "/areas/tol-dhurath/temple-exterior/4x1.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}

//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/ravine-brook.c", "north");
    addFeature("/lib/environment/features/trees/oak-stand.c", "east");

    addExit("east", "/areas/tol-dhurath/temple-exterior/11x4.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("north", "/areas/tol-dhurath/temple-exterior/10x5.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}

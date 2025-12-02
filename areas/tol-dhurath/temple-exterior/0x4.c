//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/poplar-stand.c", "southwest");
    addFeature("/lib/environment/features/water/brook.c", "east");

    addExit("north", "/areas/tol-dhurath/temple-exterior/0x5.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}

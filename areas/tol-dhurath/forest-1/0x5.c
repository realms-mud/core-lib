//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/apple-stand.c", "northwest");
    addFeature("/lib/environment/features/water/brook.c", "south");

    addExit("south", "/areas/tol-dhurath/forest-1/0x4.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("north", "/areas/tol-dhurath/forest-1/0x6.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}

//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/oak-stand.c", "northwest");
    addFeature("/lib/environment/features/water/brook.c", "northwest");

    addExit("east", "/areas/tol-dhurath/forest-5/1x6.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("south", "/areas/tol-dhurath/forest-5/0x5.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}

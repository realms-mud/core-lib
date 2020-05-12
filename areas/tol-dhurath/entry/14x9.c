//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/creek.c", "northwest");
    addFeature("/lib/environment/features/trees/oak-stand.c", "northwest");
    addFeature("/lib/environment/features/water/brook.c", "northwest");

    addExit("east", "/areas/tol-dhurath/entry/15x9.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("south", "/areas/tol-dhurath/entry/14x8.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}

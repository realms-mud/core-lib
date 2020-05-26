//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/poplar-stand.c", "south");
    addFeature("/lib/environment/features/trees/paper-birch-stand.c", "west");
    addFeature("/lib/environment/features/water/brook.c", "east");

    addExit("north", "/areas/tol-dhurath/temple-exterior/6x6.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("south", "/areas/tol-dhurath/temple-exterior/6x4.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}

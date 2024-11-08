//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/maple-stand.c", "south");
    addFeature("/lib/environment/features/water/brook.c", "east");

    addExit("north", "/areas/tol-dhurath/temple-exterior/6x7.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("south", "/areas/tol-dhurath/temple-exterior/6x5.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}

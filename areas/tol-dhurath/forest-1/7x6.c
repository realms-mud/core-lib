//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/golden-apple-stand.c", "northwest");
    addFeature("/lib/environment/features/water/brook.c", "northwest");

    addExit("south", "/areas/tol-dhurath/forest-1/7x5.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("west", "/areas/tol-dhurath/forest-1/6x6.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}

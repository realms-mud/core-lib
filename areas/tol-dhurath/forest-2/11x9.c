//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/dogwood-stand.c", "east");
    addFeature("/lib/environment/features/water/brook.c", "north");

    addExit("west", "/areas/tol-dhurath/forest-2/10x9.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("east", "/areas/tol-dhurath/forest-2/12x9.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}

//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/sugar-maple-stand.c", "east");
    addFeature("/lib/environment/features/trees/hemlock-stand.c", "west");
    addFeature("/lib/environment/features/water/brook.c", "northeast");

    addExit("west", "/areas/tol-dhurath/forest-3/21x6.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("east", "/areas/tol-dhurath/forest-3/23x6.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}

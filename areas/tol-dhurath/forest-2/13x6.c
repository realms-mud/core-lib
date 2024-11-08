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

    addExit("east", "/areas/tol-dhurath/forest-2/14x6.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("west", "/areas/tol-dhurath/forest-2/12x6.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}

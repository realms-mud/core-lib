//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/holly-stand.c", "west");
    addFeature("/lib/environment/features/trees/beech-stand.c", "west");

    addExit("east", "/areas/tol-dhurath/forest-1/18x6.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("west", "/areas/tol-dhurath/forest-1/16x6.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}

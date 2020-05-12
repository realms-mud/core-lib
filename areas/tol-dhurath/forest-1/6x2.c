//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/glen.c", "southeast");
    addFeature("/lib/environment/features/trees/golden-apple-stand.c", "southeast");

    addExit("south", "/areas/tol-dhurath/forest-1/6x1.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("east", "/areas/tol-dhurath/forest-1/7x2.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}

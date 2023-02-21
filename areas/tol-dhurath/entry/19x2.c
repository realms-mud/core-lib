//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/bluff.c", "west");
    addFeature("/lib/environment/features/trees/maple-stand.c", "south");

    addExit("east", "/areas/tol-dhurath/entry/20x2.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("north", "/areas/tol-dhurath/entry/19x3.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}

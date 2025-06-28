//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/brook.c", "southeast");
    addFeature("/lib/environment/features/trees/walnut-stand.c", "southeast");
    addFeature("/lib/environment/features/trees/elm-stand.c", "southeast");

    addExit("north", "/lib/tests/support/pathfinding/24x3.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}


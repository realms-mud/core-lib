//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/elm-stand.c", "southwest");
    addFeature("/lib/environment/features/landforms/glen.c", "southwest");
    addFeature("/lib/environment/features/trees/buckthorn-stand.c", "southwest");

    addExit("south", "/areas/tol-dhurath/forest-5/13x0.c");
    addFeature("/lib/environment/features/paths/path.c", "south");

    addRandomCreature(({"black bear","otter","chipmunk"}));
}

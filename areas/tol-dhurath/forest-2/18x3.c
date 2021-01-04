//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/knoll.c", "west");
    addFeature("/lib/environment/features/trees/sycamore-stand.c", "south");
    addFeature("/lib/environment/features/landforms/ridge.c", "southwest");

    addExit("west", "/areas/tol-dhurath/forest-2/17x3.c");
    addFeature("/lib/environment/features/paths/path.c", "west");

    addRandomCreature(({"coyote","beaver","outlaw","red fox"}));
}

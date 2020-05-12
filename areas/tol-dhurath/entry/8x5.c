//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/ridge.c", "south");
    addFeature("/lib/environment/features/landforms/sinkhole.c", "south");

    addExit("east", "/areas/tol-dhurath/entry/9x5.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("north", "/areas/tol-dhurath/entry/8x6.c");
    addFeature("/lib/environment/features/paths/path.c", "north");

    addRandomCreature(({"outlaw","coyote","brown bear","boar","gray wolf"}));
}

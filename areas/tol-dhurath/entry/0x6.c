//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/brook.c", "north");
    addFeature("/lib/environment/features/landforms/ridge.c", "west");

    addExit("south", "/areas/tol-dhurath/entry/0x5.c");
    addFeature("/lib/environment/features/paths/path.c", "south");

    addRandomCreature(({"coyote","mule deer","outlaw","red fox"}));
}

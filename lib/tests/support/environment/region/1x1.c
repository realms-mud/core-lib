//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/tests/support/environment/fakeTerrain.c");
    addFeature("/lib/tests/support/environment/fakeFeature.c", "north");
    addFeature("/lib/tests/support/environment/fakeSimpleFeature.c", "south");
    addFeature("fake feature", "east");

    addExit("west", "/lib/tests/support/environment/region/0x1.c");
    addExit("north", "/lib/tests/support/environment/region/1x2.c");
    addExit("south", "/lib/tests/support/environment/region/1x0.c");
    addExit("southeast", "/lib/tests/support/environment/region/0x2.c");
}

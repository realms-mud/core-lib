//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
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

    addExit("east", "/lib/tests/support/environment/region/2x2.c");
    addExit("north", "/lib/tests/support/environment/region/1x3.c");
    addExit("south", "/lib/tests/support/environment/region/1x1.c");
}

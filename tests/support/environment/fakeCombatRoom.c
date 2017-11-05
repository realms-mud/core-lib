//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    set_light(1);
    setTerrain("/lib/tests/support/environment/fakeTerrain.c");
    addFeature("/lib/tests/support/environment/fakeFeature.c", "north");
    addFeature("/lib/tests/support/environment/fakeSimpleFeature.c", "south");
    addBuilding("/lib/tests/support/environment/fakeBuilding.c", "west", "/some/path/location.c");
    addFeature("fake feature", "east");
    addItem("/lib/tests/support/environment/fakeItem.c", "north");

    addExit("south", "/some/path.c");
}


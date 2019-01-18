//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    cloneEnvironment();
    setTerrain("/lib/tests/support/environment/fakeTerrain.c");
    addFeature("/lib/tests/support/environment/fakeFeature.c", "north");
    addFeature("/lib/tests/support/environment/fakeSimpleFeature.c", "south");
    addFeature("fake feature", "east");

    addExit("west", "/lib/tests/support/environment/secondClonedRoom.c");
    addExit("south", "/lib/tests/support/environment/notClonedRoom.c");
}

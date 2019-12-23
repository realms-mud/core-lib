//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/tests/support/environment/fakeInterior.c");
    addFeature("/lib/tests/support/environment/fakeFeature.c", "north");
    addFeature("/lib/tests/support/environment/fakeSimpleFeature.c", "south");
    addItem("/lib/tests/support/environment/light.c");
    addFeature("fake feature", "east");

    addExit("east", "/lib/tests/support/environment/startingRoom.c");

    addObject("/lib/items/weapon.c", "someState");
    addObject("/tutorial/characters/keeper-of-the-night.c");
    setAdditionalLongDescription("This is an extra long description to be "
        "displayed after the feature descriptions");
}

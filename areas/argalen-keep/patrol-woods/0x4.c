//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/argalen-keep/patrol-woods/woodlandRoom.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setUpWoodlandRoom();
    addDecorator("forest trail east-west");
    addFeature("/lib/environment/features/paths/trail.c", "east");
    addFeature("/lib/environment/features/paths/trail.c", "west");
    addItem("/lib/environment/items/objects/tol-dhurath-marker.c", "north");

    addExit("west", "/areas/tol-dhurath/entry/17x0.c");
    addExit("east", "/areas/argalen-keep/patrol-woods/1x4.c");
}

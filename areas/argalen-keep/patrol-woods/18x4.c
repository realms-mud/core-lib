//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/argalen-keep/patrol-woods/woodlandRoom.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setUpWoodlandRoom();
    addDecorator("forest trail T-north");
    addFeature("/lib/environment/features/paths/trail.c", "east");
    addFeature("/lib/environment/features/paths/trail.c", "west");
    addFeature("/lib/environment/features/paths/trail.c", "north");
    addItem("/lib/environment/items/objects/outlaw-warning-sign.c",
        "north");

    addExit("west", "/areas/argalen-keep/patrol-woods/17x4.c");
    addExit("east", "/areas/argalen-keep/patrol-woods/19x4.c");
    addExit("north", "/areas/argalen-keep/patrol-woods/18x3.c");
}

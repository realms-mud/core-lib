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
    addFeature("/lib/environment/features/trees/oak-stand.c", "south");

    addExit("west", "/areas/argalen-keep/patrol-woods/19x4.c");
    addExit("east", "/areas/argalen-keep/patrol-woods/21x4.c");
}

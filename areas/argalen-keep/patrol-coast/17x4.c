//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/argalen-keep/patrol-coast/coastalRoom.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setUpCoastalRoom();
    addDecorator("coast trail T-south");
    addFeature("/lib/environment/features/paths/trail.c", "east");
    addFeature("/lib/environment/features/paths/trail.c", "west");
    addFeature("/lib/environment/features/paths/trail.c", "south");

    addExit("west", "/areas/argalen-keep/patrol-coast/16x4.c");
    addExit("east", "/areas/argalen-keep/patrol-coast/18x4.c");
    addExit("south", "/areas/argalen-keep/patrol-coast/17x5.c");
}

//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/argalen-keep/patrol-coast/coastalRoom.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setUpCoastalRoom();
    addDecorator("coast trail T-north");
    addFeature("/lib/environment/features/paths/trail.c", "north");
    addFeature("/lib/environment/features/paths/trail.c", "east");
    addFeature("/lib/environment/features/paths/trail.c", "west");

    addExit("north", "/areas/argalen-keep/patrol-coast/12x3.c");
    addExit("east", "/areas/argalen-keep/patrol-coast/13x4.c");
    addExit("west", "/areas/argalen-keep/patrol-coast/11x4.c");
}

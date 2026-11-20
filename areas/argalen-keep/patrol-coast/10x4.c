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
    addItem("/lib/environment/items/marine/fishing-net.c", "north");

    addExit("east", "/areas/argalen-keep/patrol-coast/11x4.c");
    addExit("west", "/areas/argalen-keep/patrol-coast/9x4.c");
    addExit("south", "/areas/argalen-keep/patrol-coast/10x5.c");
}

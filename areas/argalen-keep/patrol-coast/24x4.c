//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/argalen-keep/patrol-coast/coastalRoom.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setUpCoastalRoom();
    addDecorator("coast trail north-west corner");
    addFeature("/lib/environment/features/paths/trail.c", "west");
    addFeature("/lib/environment/features/paths/trail.c", "north");
    addItem("/lib/environment/items/marine/tide-marker.c", "east");
    addExit("north", "/areas/northern-road/northern-manor/19x6.c");

    addExit("west", "/areas/argalen-keep/patrol-coast/23x4.c");
}

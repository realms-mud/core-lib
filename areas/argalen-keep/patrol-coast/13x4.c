//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/argalen-keep/patrol-coast/coastalRoom.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setUpCoastalRoom();
    addDecorator("coast trail east-west");
    addFeature("/lib/environment/features/paths/trail.c", "east");
    addFeature("/lib/environment/features/paths/trail.c", "west");
    addItem("/lib/environment/items/marine/tide-marker.c", "north");

    addExit("west", "/areas/argalen-keep/patrol-coast/12x4.c");
    addExit("east", "/areas/argalen-keep/patrol-coast/14x4.c");
}

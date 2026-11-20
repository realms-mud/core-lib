//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/argalen-keep/patrol-coast/coastalRoom.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setUpCoastalRoom();
    addDecorator("coast trail west entry");
    addFeature("/lib/environment/features/paths/trail.c", "west");
    addItem("/lib/environment/items/marine/tide-marker.c", "east");

    addExit("west", "/areas/argalen-keep/patrol-coast/23x4.c");
}

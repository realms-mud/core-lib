//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/argalen-keep/patrol-coast/coastalRoom.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setUpCoastalRoom();
    addDecorator("coast trail north-south");
    addFeature("/lib/environment/features/paths/trail.c", "north");
    addFeature("/lib/environment/features/paths/trail.c", "south");
    addItem("/lib/environment/items/marine/torn-fishing-net.c", "west");
    addItem("/lib/environment/items/objects/outlaw-warning-sign.c", "east");
    setEncounterLevel(3);
    addRandomCreature(({ "outlaw" }));

    addExit("north", "/areas/argalen-keep/patrol-coast/17x4.c");
    addExit("south", "/areas/argalen-keep/patrol-coast/17x6.c");
}

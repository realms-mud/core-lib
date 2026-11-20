//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/argalen-keep/patrol-coast/coastalRoom.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setUpCoastalRoom();
    addDecorator("rocky shore");
    addFeature("/lib/environment/features/paths/trail.c", "north");
    addFeature("/lib/environment/features/water/tidal-pool.c", "west");
    addItem("/lib/environment/items/marine/tide-marker.c", "south");
    setEncounterLevel(2);
    addRandomCreature(({ "otter" }));

    addExit("north", "/areas/argalen-keep/patrol-coast/17x5.c");
}

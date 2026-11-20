//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/argalen-keep/patrol-woods/woodlandRoom.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setUpWoodlandRoom();
    addDecorator("forest trail south");
    addFeature("/lib/environment/features/paths/trail.c", "south");
    addFeature("/lib/environment/features/trees/juniper-shrubs.c", "east");
    addItem("/lib/environment/items/objects/broken-cart.c", "west");
    setEncounterLevel(4);
    addRandomCreature(({ "outlaw" }));

    addExit("south", "/areas/argalen-keep/patrol-woods/18x4.c");
}

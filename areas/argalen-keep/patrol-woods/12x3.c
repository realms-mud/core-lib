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
    addItem("/lib/environment/items/objects/hunter-shelter.c", "north");
    addNonCombatCreature(({ "forester" }));

    addExit("south", "/areas/argalen-keep/patrol-woods/12x4.c");
}

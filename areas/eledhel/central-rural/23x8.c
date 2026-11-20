//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/ruin.c");
    setShortDescription("The disused root cellar");
    addDecorator("ruined interior east-west hallway");
    addItem("/lib/environment/items/objects/sack-pile.c", "south");
    addItem("/lib/environment/items/records/ledger-desk.c", "east");
    addFeature("/lib/environment/features/caves/timber-supports.c",
        "north");
    setEncounterLevel(2);
    addRandomCreature(({ "bat" }));
    addExitWithDoor("west", "/areas/eledhel/central-rural/22x8.c",
        "/lib/environment/doors/plank-door.c");
    addExitWithDoor("east",
        "/areas/eledhel/central-rural/cellar/2x2.c",
        "/lib/environment/doors/plank-door.c");
}

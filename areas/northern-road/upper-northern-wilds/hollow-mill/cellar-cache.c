//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/workshop.c");
    addItem("/lib/environment/items/crafts/flour-sack.c", "north");
    addItem("/lib/environment/items/furniture/cabinet.c", "east");
    addItem("/lib/environment/items/objects/broken-cart.c", "south");
    addItem("/lib/environment/items/objects/notice-board.c", "west");
    setEncounterLevel(6);
    addRandomCreature(({ "outlaw", "ruffian" }));
    addExit("west",
        "/areas/northern-road/upper-northern-wilds/hollow-mill/cellar-entry.c");
}

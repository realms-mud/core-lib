//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/investigationRoom.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/wood-interior.c");
    addItem("/lib/environment/items/records/ledger-desk.c", "east");
    addItem("/lib/environment/items/objects/notice-board.c", "west");
    addItem("/lib/environment/items/lighting/window.c", "north");
    addItem("/lib/environment/items/furniture/bench.c", "south");
    addInvestigationClue("waystation ledger",
        "/areas/minlach/quests/road-measure.c", "checkWaystations",
        "The ledger records sheltered stops, passable approaches, and "
        "two bridges that need minor work. It also notes where patrols "
        "can safely water and rest without entering private holdings.");

    addExitWithDoor("west", "/areas/tol-dhurath/forest-2/15x7.c",
        "/lib/environment/doors/plank-door.c");
}

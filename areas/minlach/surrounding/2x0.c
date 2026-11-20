//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/areas/minlach/investigation-room.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/wood-interior.c");
    addDecorator("keep interior north entry alcove");
    setShortDescription("The forester's lodge");
    addItem("/lib/environment/items/records/ledger-desk.c", "east");
    addItem("/lib/environment/items/objects/notice-board.c", "west");
    addItem("/lib/environment/items/lighting/window.c", "north");
    addItem("/lib/environment/items/lighting/oil-lamp.c", "east");
    addObject("/areas/minlach/characters/maelin/maelin.c");
    addClue("tenant fuel permit", "woodland-boundary", "readTenantFuelPermit",
        "The tenant's winter-fuel grant allows fallen branches "
        "only. It does not authorize cutting standing timber.");
    addExitWithDoor("north", "/areas/minlach/surrounding/2x1.c",
        "/lib/environment/doors/plank-door.c");
}

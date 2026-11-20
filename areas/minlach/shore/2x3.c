//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/areas/minlach/investigation-room.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/sandy-shoreline.c");
    addDecorator("sandy shore");
    setShortDescription("The beached fishing boat");
    addItem("/lib/environment/items/marine/rowboat.c", "east");
    addItem("/lib/environment/items/records/cargo-slate.c", "east");
    addItem("/lib/environment/items/marine/coiled-rope.c", "north");
    addClue("boat slate", "false-harbor-light", "readBoatSlate",
        "The crew recorded unloading under pressure after "
        "following a low shore light. They went to the harbor "
        "refuge, leaving this slate as an account.");
    addExit("west", "/areas/minlach/shore/1x3.c");
    addExit("south", "/areas/minlach/shore/2x2.c");
}

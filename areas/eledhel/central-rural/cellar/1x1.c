//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/ruin.c");
    addDecorator("ruined interior east entry alcove");
    addItem("/lib/environment/items/objects/packing-crate.c", "north");
    addItem("/areas/eledhel/central-rural/items/farm-tally-board.c",
        "south");

    addExit("east", "/areas/eledhel/central-rural/cellar/2x1.c");
}

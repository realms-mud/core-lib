//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/keep.c");
    addItem(
        "/areas/northern-road/minlach-approaches/items/toll-ledger.c",
        "west");
    addItem("/lib/environment/items/lighting/lantern.c", "east");
    addItem("/lib/environment/items/military/supply-crate.c", "south");
    addDecorator("village keep gate");

    addExit("south", "/areas/northern-road/minlach-approaches/12x2.c");
}

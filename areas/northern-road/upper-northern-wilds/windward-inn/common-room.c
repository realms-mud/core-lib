//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/inn.c");
    addItem("/lib/environment/items/furniture/long-table.c", "east");
    addItem("/lib/environment/items/lighting/hearth.c", "north");
    addItem("/lib/environment/items/furniture/bench.c", "west");
    addObject("/areas/northern-road/upper-northern-wilds/characters/innkeeper.c");

    addExit("east", "/areas/northern-road/upper-northern-wilds/0x0.c");
    addExit("west", "/areas/northern-road/upper-northern-wilds/windward-inn/loft.c");
    addExit("south", "/areas/northern-road/upper-northern-wilds/windward-inn/stable-yard.c");
}

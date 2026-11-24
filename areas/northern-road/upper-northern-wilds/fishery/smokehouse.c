//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/wood-interior.c");
    addItem("/lib/environment/items/marine/fish-cleaning-table.c", "east");
    addItem("/lib/environment/items/marine/crate-of-fish.c", "north");
    addItem("/lib/environment/items/lighting/hearth.c", "west");
    addExit("north",
        "/areas/northern-road/upper-northern-wilds/fishery/net-yard.c");
    addExit("west",
        "/areas/northern-road/upper-northern-wilds/fishery/tide-cave.c");
    addExit("east",
        "/areas/northern-road/upper-northern-wilds/fishery/ebb-rocks.c");
}

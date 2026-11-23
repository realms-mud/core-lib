//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

public void Setup()
{
    setInterior("/lib/environment/interiors/kitchen.c");
    setShortDescription("A small kitchen keeps the tavern's stew and "
        "bread ready for its regulars.");
    addItem("/lib/environment/items/furniture/pantry.c", "north");
    addItem("/lib/environment/items/furniture/long-table.c", "east");
    addExit("south", "/areas/eledhel/central-city/tavern/0x0.c");
}

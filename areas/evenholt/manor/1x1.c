//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/wood-interior.c");
    addDecorator("keep interior 4-way hallway");
    setShortDescription("The dining room");
    addItem("/lib/environment/items/furniture/long-table.c", "north");
    addItem("/lib/environment/items/furniture/bench.c", "south");
    addExit("west", "/areas/evenholt/manor/0x1.c");
    addExit("east", "/areas/evenholt/manor/2x1.c");
    addExit("north", "/areas/evenholt/manor/1x0.c");
    addExit("south", "/areas/evenholt/manor/1x2.c");
}

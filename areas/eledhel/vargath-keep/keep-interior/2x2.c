//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/stone-keep.c");
    addDecorator("keep interior floor");
    setShortDescription("The bailey is crowded with wagons and iron crates");
    addItem("/lib/environment/items/furniture/long-table.c", "none");
    addExit("west", "/areas/eledhel/vargath-keep/keep-interior/1x2.c");
    addExit("east", "/areas/eledhel/vargath-keep/keep-interior/3x2.c");
    addExit("north", "/areas/eledhel/vargath-keep/keep-interior/2x1.c");
    addExit("south", "/areas/eledhel/vargath-keep/keep-interior/2x3.c");
    addRandomCreature(({ "outlaw", "knight of the storm" }));
}

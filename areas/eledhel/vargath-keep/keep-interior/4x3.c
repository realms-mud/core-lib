//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/stone-keep.c");
    addDecorator("keep interior north-west corner hallway");
    setShortDescription("A guard room watches the gate controls");
    addItem("/lib/environment/items/furniture/table.c", "none");
    addExit("west", "/areas/eledhel/vargath-keep/keep-interior/3x3.c");
    addExit("north", "/areas/eledhel/vargath-keep/keep-interior/4x2.c");
    addRandomCreature(({ "keeper of the night", "knight of the storm" }));
}

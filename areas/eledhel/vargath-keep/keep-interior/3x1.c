//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/stone-keep.c");
    addDecorator("keep interior floor");
    setShortDescription("A narrow officer's room overlooks the bailey");
    addItem("/lib/environment/items/furniture/table.c", "none");
    addExit("west", "/areas/eledhel/vargath-keep/keep-interior/2x1.c");
    addExit("east", "/areas/eledhel/vargath-keep/keep-interior/4x1.c");
    addExit("south", "/areas/eledhel/vargath-keep/keep-interior/3x2.c");
    addRandomCreature(({ "knight of the storm" }));
}

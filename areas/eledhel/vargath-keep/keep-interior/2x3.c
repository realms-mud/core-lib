//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/stone-keep.c");
    addDecorator("keep interior floor");
    setShortDescription("The garrison barracks crowd the lower bailey");
    addItem("/lib/environment/items/furniture/bed.c", "none");
    addExit("west", "/areas/eledhel/vargath-keep/keep-interior/1x3.c");
    addExit("east", "/areas/eledhel/vargath-keep/keep-interior/3x3.c");
    addExit("north", "/areas/eledhel/vargath-keep/keep-interior/2x2.c");
    addRandomCreature(({ "keeper of the night", "knight of the storm" }));
}

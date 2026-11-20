//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/stone-keep.c");
    addDecorator("keep interior floor");
    setShortDescription("Vargath holds audience beneath the keep's carved "
        "ceiling");
    addItem("/lib/environment/items/furniture/long-table.c", "none");
    addObject("/areas/eledhel/vargath-keep/characters/vargath.c");
    addObject("/areas/eledhel/vargath-keep/characters/gaelrich.c");
    addObject("/areas/eledhel/vargath-keep/characters/meric.c");
    addRandomCreature(({ "keeper of the night" }));
    addExit("west", "/areas/eledhel/vargath-keep/keep-interior/2x2.c");
    addExit("east", "/areas/eledhel/vargath-keep/keep-interior/4x2.c");
    addExit("north", "/areas/eledhel/vargath-keep/keep-interior/3x1.c");
    addExit("south", "/areas/eledhel/vargath-keep/keep-interior/3x3.c");
}

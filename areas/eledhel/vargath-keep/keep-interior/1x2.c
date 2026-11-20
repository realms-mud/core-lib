//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/stone-keep.c");
    addDecorator("keep interior 4-way hallway");
    setShortDescription("A guarded passage joins the bailey and service rooms");
    addItem("/lib/environment/items/lighting/lit-sconce.c", "east");
    addExit("west", "/areas/eledhel/vargath-keep/keep-interior/0x2.c");
    addExit("east", "/areas/eledhel/vargath-keep/keep-interior/2x2.c");
    addExit("north", "/areas/eledhel/vargath-keep/keep-interior/1x1.c");
    addExit("south", "/areas/eledhel/vargath-keep/keep-interior/1x3.c");
    addRandomCreature(({ "knight of the storm", "ruffian" }));
}

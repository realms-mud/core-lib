//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/stone-keep.c");
    addDecorator("keep interior floor");
    setShortDescription("The armory's iron racks stand above a weapon bench");
    addItem("/lib/environment/items/crafts/anvil.c", "none");
    addExit("west", "/areas/eledhel/vargath-keep/keep-interior/1x1.c");
    addExit("east", "/areas/eledhel/vargath-keep/keep-interior/3x1.c");
    addExit("south", "/areas/eledhel/vargath-keep/keep-interior/2x2.c");
}

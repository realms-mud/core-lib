//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/stone-keep.c");
    setShortDescription("The Aladain great hall");
    addDecorator("keep interior north-south hallway west entry");
    addItem("/lib/environment/items/lighting/lit-sconce.c", "west");
    addItem("/lib/environment/items/records/ledger-desk.c", "east");
    addExit("south", "/areas/eledhel/estates/aladain/keep-interior/2x0.c");
    addExit("north", "/areas/eledhel/estates/aladain/keep-interior/2x2.c");
    addExit("west", "/areas/eledhel/estates/aladain/keep-interior/1x1.c");
}

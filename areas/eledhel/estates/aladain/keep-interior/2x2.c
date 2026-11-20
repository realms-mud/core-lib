//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/stone-keep.c");
    setShortDescription("The estate records room");
    addDecorator("keep interior south-east corner hallway");
    addItem("/lib/environment/items/records/ledger-desk.c", "west");
    addItem("/lib/environment/items/lighting/lit-sconce.c", "east");
    addExit("south", "/areas/eledhel/estates/aladain/keep-interior/2x1.c");
    addExit("east", "/areas/eledhel/estates/aladain/keep-interior/3x2.c");
}

//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/stone-keep.c");
    addDecorator("keep interior south-east corner hallway");
    setShortDescription("A records room holds the iron dispatch orders");
    addItem("/areas/eledhel/vargath-keep/items/dispatch-ledger.c", "none");
    addExit("south", "/areas/eledhel/vargath-keep/keep-interior/1x2.c");
    addExit("east", "/areas/eledhel/vargath-keep/keep-interior/2x1.c");
}

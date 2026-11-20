//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/stone-keep.c");
    setShortDescription("The steward's office");
    addDecorator("keep interior east wall entry");
    addItem("/lib/environment/items/records/ledger-desk.c", "north");
    addObject("/areas/eledhel/estates/aladain/characters/steward.c");
    addExit("east", "/areas/eledhel/estates/aladain/keep-interior/2x1.c");
}

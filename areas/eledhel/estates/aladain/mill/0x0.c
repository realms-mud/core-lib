//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/craft-workroom.c");
    setShortDescription("The Aladain estate mill floor");
    addItem("/lib/environment/items/crafts/flour-sack.c", "west");
    addItem("/lib/environment/items/records/ledger-desk.c", "east");
    addItem("/lib/environment/items/lighting/oil-lamp.c", "north");
    addObject("/areas/eledhel/estates/aladain/characters/miller.c");
    addExitWithDoor("west", "/areas/eledhel/estates/aladain/grounds/3x2.c",
        "/lib/environment/doors/plank-door.c");
}

//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/wood-interior.c");

    addItem("/lib/environment/items/crafts/grain-bin.c", "north");
    addItem("/lib/environment/items/objects/sack-pile.c", "west");
    addItem("/lib/environment/items/lighting/oil-lamp.c", "east");

    addExitWithDoor("north",
        "/areas/eledhel/estates/belectar/grounds/0x2.c",
        "/lib/environment/doors/plank-door.c");
}

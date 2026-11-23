//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/wood-interior.c");

    addItem("/lib/environment/items/objects/hay-bale.c", "north");
    addItem("/lib/environment/items/objects/feeding-trough.c", "south");
    addItem("/lib/environment/items/lighting/oil-lamp.c", "west");

    addExitWithDoor("east",
        "/areas/eledhel/estates/kirin/grounds/0x1.c",
        "/lib/environment/doors/plank-door.c");
}

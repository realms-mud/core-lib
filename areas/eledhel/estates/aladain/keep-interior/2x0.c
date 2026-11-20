//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/stone-keep.c");
    setShortDescription("The keep's entry hall");
    addDecorator("keep interior north-south hallway");
    addItem("/lib/environment/items/lighting/lit-sconce.c", "east");
    addExitWithDoor("south",
        "/areas/eledhel/estates/aladain/grounds/3x4.c",
        "/lib/environment/doors/plank-door.c");
    addExit("north", "/areas/eledhel/estates/aladain/keep-interior/2x1.c");
}

//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/wood-interior.c");
    setShortDescription("The Llenwych manor entrance facing the yard");
    addDecorator("keep interior floor");
    addItem("/lib/environment/items/lighting/lit-sconce.c", "east");
    addExitWithDoor("south",
        "/areas/eledhel/estates/llenwych/grounds/2x2.c",
        "/lib/environment/doors/plank-door.c");
    addExit("north", "/areas/eledhel/estates/llenwych/manor-interior/2x1.c");
}

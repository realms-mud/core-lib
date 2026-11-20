//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/wood-interior.c");
    setShortDescription("The meal room at Urdhan Manor");
    addDecorator("keep interior floor");
    addItem("/lib/environment/items/lighting/lit-sconce.c", "east");
    addExit("west", "/areas/eledhel/estates/urdhan/manor-interior/2x1.c");
}

//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/wood-interior.c");
    setShortDescription("The working hall at Urdhan Manor");
    addDecorator("keep interior north-south hallway");
    addItem("/lib/environment/items/lighting/lit-sconce.c", "west");
    addExit("south", "/areas/eledhel/estates/urdhan/manor-interior/2x0.c");
    addExit("west", "/areas/eledhel/estates/urdhan/manor-interior/1x1.c");
    addExit("east", "/areas/eledhel/estates/urdhan/manor-interior/3x1.c");
    addExit("north",
        "/areas/eledhel/estates/urdhan/manor-interior/2x2.c");
}

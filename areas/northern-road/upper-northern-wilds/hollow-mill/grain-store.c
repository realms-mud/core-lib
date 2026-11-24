//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/workshop.c");
    setShortDescription("The dry store above the mill race");
    addItem("/lib/environment/items/crafts/flour-sack.c", "west");
    addItem("/lib/environment/items/crafts/flour-sack.c", "north");
    addItem("/lib/environment/items/furniture/cabinet.c", "east");
    addItem("/lib/environment/items/crafts/mill-hopper.c", "south");
    addExit("south",
        "/areas/northern-road/upper-northern-wilds/hollow-mill/yard.c");
    addExit("east",
        "/areas/northern-road/upper-northern-wilds/hollow-mill/wheel-room.c");
}

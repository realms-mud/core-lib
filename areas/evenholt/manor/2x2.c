//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/bedroom.c");
    addDecorator("keep interior north T-intersection");
    setShortDescription("A second guest sleeping room");
    addItem("/lib/environment/items/furniture/bed.c", "north");
    addItem("/lib/environment/items/furniture/wardrobe.c", "east");
    addExit("west", "/areas/evenholt/manor/1x2.c");
    addExit("east", "/areas/evenholt/manor/3x2.c");
    addExit("north", "/areas/evenholt/manor/2x1.c");
}

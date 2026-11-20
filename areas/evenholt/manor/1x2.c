//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/hallway.c");
    addDecorator("keep interior north T-intersection");
    setShortDescription("The upstairs passage");
    addItem("/lib/environment/items/furniture/chest-bench.c", "south");
    addExit("west", "/areas/evenholt/manor/0x2.c");
    addExit("east", "/areas/evenholt/manor/2x2.c");
    addExit("north", "/areas/evenholt/manor/1x1.c");
}

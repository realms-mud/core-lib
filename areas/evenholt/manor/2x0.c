//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/study.c");
    addDecorator("keep interior south T-intersection");
    setShortDescription("The map room and working study");
    addItem("/lib/environment/items/furniture/writing-desk.c", "north");
    addItem("/lib/environment/items/furniture/chair.c", "east");
    addExit("west", "/areas/evenholt/manor/1x0.c");
    addExit("east", "/areas/evenholt/manor/3x0.c");
    addExit("south", "/areas/evenholt/manor/2x1.c");
}

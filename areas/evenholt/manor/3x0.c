//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/study.c");
    addDecorator("keep interior south-west corner hallway");
    setShortDescription("The small classroom");
    addItem("/lib/environment/items/furniture/long-table.c", "north");
    addItem("/lib/environment/items/furniture/chair.c", "east");
    addExit("west", "/areas/evenholt/manor/2x0.c");
    addExit("south", "/areas/evenholt/manor/3x1.c");
}

//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/wood-interior.c");
    addDecorator("keep interior south-east corner hallway");
    setShortDescription("The quiet sitting room");
    addItem("/lib/environment/items/furniture/chair.c", "east");
    addItem("/lib/environment/items/furniture/small-table.c", "west");
    addExit("south", "/areas/evenholt/manor/0x1.c");
    addExit("east", "/areas/evenholt/manor/1x0.c");
}

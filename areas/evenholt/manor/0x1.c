//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/wood-interior.c");
    addDecorator("keep interior east T-intersection");
    setShortDescription("The front hall");
    addItem("/lib/environment/items/furniture/bench.c", "west");
    addExit("south", "/areas/evenholt/grounds/20x4.c");
    addExit("north", "/areas/evenholt/manor/0x0.c");
    addExit("east", "/areas/evenholt/manor/1x1.c");
}

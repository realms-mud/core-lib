//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/wood-interior.c");
    addDecorator("keep interior west T-intersection");
    setShortDescription("The pantry and side door");
    addItem("/lib/environment/items/furniture/pantry.c", "east");
    addExit("west", "/areas/evenholt/manor/2x1.c");
    addExit("north", "/areas/evenholt/manor/3x0.c");
    addExit("south", "/areas/evenholt/manor/3x2.c");
    addExit("down", "/areas/evenholt/manor-cellar/0x0.c");
}

//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/wood-interior.c");
    addDecorator("keep interior north-west corner hallway");
    setShortDescription("The quiet end of the sleeping passage");
    addItem("/lib/environment/items/furniture/chest.c", "west");
    addExit("west", "/areas/evenholt/manor/2x2.c");
    addExit("north", "/areas/evenholt/manor/3x1.c");
}

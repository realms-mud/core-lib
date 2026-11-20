//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/kitchen.c");
    addDecorator("keep interior 4-way hallway");
    setShortDescription("The kitchen");
    addItem("/lib/environment/items/furniture/counter.c", "north");
    addItem("/lib/environment/items/furniture/hutch.c", "west");
    addObject("/areas/evenholt/characters/lydia.c");
    addExit("west", "/areas/evenholt/manor/1x1.c");
    addExit("east", "/areas/evenholt/manor/3x1.c");
    addExit("north", "/areas/evenholt/manor/2x0.c");
    addExit("south", "/areas/evenholt/manor/2x2.c");
}

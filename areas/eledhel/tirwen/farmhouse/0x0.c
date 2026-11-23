//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/wood-interior.c");
    setShortDescription("The working room of Tirwen farmhouse");
    addDecorator("keep interior floor");
    addItem("/lib/environment/items/objects/sack-pile.c", "west");
    addObject("/areas/eledhel/tirwen/characters/rilwen/rilwen.c");
    addExit("south", "/areas/eledhel/tirwen/farmhouse/0x1.c");
}

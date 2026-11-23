//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/craft-workroom.c");
    setShortDescription("The working room around Dhorlen's millstones");
    addDecorator("keep interior floor");
    addItem("/lib/environment/items/crafts/millstone.c", "east");
    addObject("/areas/eledhel/dhorlen/characters/nereth/nereth.c");
    addExit("south", "/areas/eledhel/dhorlen/mill/0x1.c");
}

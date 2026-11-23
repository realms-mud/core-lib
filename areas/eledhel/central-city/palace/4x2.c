//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/study.c");
    addItem("/lib/environment/items/furniture/writing-desk.c", "north");
    addItem("/lib/environment/items/furniture/scribes-desk.c", "east");
    addObject("/areas/eledhel/central-city/palace/characters/chamberlain.c");
    addDecorator("palace interior");

    addExit("north", "/areas/eledhel/central-city/palace/4x1.c");
    addExit("west", "/areas/eledhel/central-city/palace/3x2.c");
    addExit("south", "/areas/eledhel/central-city/palace/4x3.c");
    addExit("east", "/areas/eledhel/central-city/palace/5x2.c");
}

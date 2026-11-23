//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/bedroom.c");
    addItem("/lib/environment/items/furniture/canopy-bed.c", "north");
    addItem("/lib/environment/items/furniture/window-seat.c", "east");
    addItem("/lib/environment/items/furniture/wardrobe.c", "west");
    addDecorator("palace 2x3");
    addObject("/areas/eledhel/central-city/palace/characters/morwen.c");

    addExit("north", "/areas/eledhel/central-city/palace/2x2.c");
    addExit("east", "/areas/eledhel/central-city/palace/3x3.c");
    addExit("west", "/areas/eledhel/central-city/palace/1x3.c");
    addExit("down", "/areas/eledhel/central-city/palace/hidden-passage.c");
}

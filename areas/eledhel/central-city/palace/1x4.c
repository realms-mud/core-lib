//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/hallway.c");
    addItem("/lib/environment/items/furniture/settle.c", "west");
    addItem("/lib/environment/items/lighting/lit-sconce.c", "east");
    addDecorator("palace 1x4");

    addExit("west", "/areas/eledhel/central-city/palace/0x4.c");
    addExit("east", "/areas/eledhel/central-city/palace/2x4.c");
    addExit("north", "/areas/eledhel/central-city/palace/1x3.c");
}

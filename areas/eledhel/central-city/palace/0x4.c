//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/guard-room.c");
    addItem("/lib/environment/items/furniture/bench.c", "west");
    addItem("/lib/environment/items/lighting/lit-sconce.c", "south");
    addDecorator("palace 0x4");

    addExit("north", "/areas/eledhel/central-city/palace/0x3.c");
    addExit("east", "/areas/eledhel/central-city/palace/1x4.c");
}

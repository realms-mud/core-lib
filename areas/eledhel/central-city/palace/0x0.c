//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/guard-room.c");
    addItem("/lib/environment/items/furniture/rack.c", "north");
    addItem("/lib/environment/items/objects/flagpole.c", "east");
    addDecorator("palace 0x0");

    addExit("east", "/areas/eledhel/central-city/palace/1x0.c");
    addExit("south", "/areas/eledhel/central-city/palace/0x1.c");
}

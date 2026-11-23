//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/wood-interior.c");
    addItem("/lib/environment/items/furniture/rack.c", "north");
    addItem("/lib/environment/items/objects/wooden-fence.c", "east");
    addDecorator("palace 5x1");

    addExit("north", "/areas/eledhel/central-city/palace/5x1.c");
    addExit("west", "/areas/eledhel/central-city/palace/4x2.c");
    addExit("south", "/areas/eledhel/central-city/palace/5x3.c");
}

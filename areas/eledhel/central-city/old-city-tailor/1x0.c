//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/workshop.c");
    setShortDescription("The tailor's quiet measuring and sewing room");
    addItem("/lib/environment/items/furniture/mirror.c", "north");
    addItem("/lib/environment/items/furniture/workbench.c", "east");
    addItem("/lib/environment/items/furniture/bench.c", "west");

    addExit("west", "/areas/eledhel/central-city/old-city-tailor/0x0.c");
}

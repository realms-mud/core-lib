//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/workshop.c");
    setShortDescription("The wool-sorting shed");
    addDecorator("village cottage");
    addItem("/lib/environment/items/lighting/oil-lamp.c", "north");
    addItem("/lib/environment/items/furniture/trestle-table.c", "none");
    addExit("south", "/areas/eledhel/southwest-rural-five/13x4.c");
    addObject("/areas/eledhel/southwest-rural-five/characters/wool-worker.c");
}

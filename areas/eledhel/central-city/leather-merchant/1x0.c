//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/workshop.c");
    setShortDescription("The leatherworker's cutting and repair room");
    addItem("/lib/environment/items/furniture/workbench.c", "north");
    addItem("/lib/environment/items/furniture/small-shelf.c", "east");

    addExit("west", "/areas/eledhel/central-city/leather-merchant/0x0.c");
}

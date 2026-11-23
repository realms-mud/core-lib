//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/workshop.c");
    setShortDescription("The shipyard's loft for sailcloth and rigging");
    addItem("/lib/environment/items/furniture/workbench.c", "east");
    addItem("/lib/environment/items/furniture/small-shelf.c", "west");
    addExit("south", "/areas/eledhel/southern-city/shipyard/1x0.c");
}

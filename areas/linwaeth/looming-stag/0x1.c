//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/inn.c");
    setShortDescription("The common room of the Looming Stag");
    addDecorator("keep interior floor");
    addItem("/lib/environment/items/furniture/counter.c", "north");
    addItem("/lib/environment/items/furniture/long-table.c", "none");
    addItem("/lib/environment/items/lighting/fireplace.c", "east");
    addObject("/areas/linwaeth/characters/inaeus-innkeeper.c");
    addExit("east", "/areas/linwaeth/looming-stag/1x1.c");
}

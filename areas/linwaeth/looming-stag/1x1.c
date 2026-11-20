//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/inn.c");
    setShortDescription("The Looming Stag's dining room");
    addDecorator("keep interior floor");
    addItem("/lib/environment/items/furniture/long-table.c", "none");
    addExit("east", "/areas/linwaeth/looming-stag/2x1.c");
    addExit("west", "/areas/linwaeth/looming-stag/0x1.c");
    addExit("south", "/areas/linwaeth/looming-stag/1x2.c");
}

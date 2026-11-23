//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/stone-keep.c");
    addItem("/lib/environment/items/furniture/bench.c", "north");
    addItem("/lib/environment/items/furniture/lectern.c", "east");

    addExit("west", "/areas/eledhel/southern-city/halls-of-justice/0x0.c");
    addExit("north", "/areas/eledhel/southern-city/halls-of-justice/0x2.c");
    addExit("east", "/areas/eledhel/southern-city/halls-of-justice/1x1.c");
}

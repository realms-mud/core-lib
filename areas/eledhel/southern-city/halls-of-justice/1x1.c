//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/banquet-hall.c");
    addItem("/lib/environment/items/furniture/long-table.c", "north");
    addItem("/lib/environment/items/lighting/lit-sconce.c", "west");
    addObject("/areas/eledhel/southern-city/halls-of-justice/characters/"
        "acolyte.c");

    addExit("west", "/areas/eledhel/southern-city/halls-of-justice/0x1.c");
}

//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/stone-keep.c");
    addItem("/lib/environment/items/furniture/bench.c", "south");
    addItem("/lib/environment/items/lighting/lit-sconce.c", "east");
    addObject("/areas/eledhel/southern-city/halls-of-justice/characters/"
        "petitioner.c");

    addExit("south", "/areas/eledhel/southern-city/halls-of-justice/0x1.c");
    addExit("east", "/areas/eledhel/southern-city/halls-of-justice/1x2.c");
}

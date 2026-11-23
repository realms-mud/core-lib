//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/stone-temple.c");
    setShortDescription("The entrance hall of the Werric outpost");
    addItem("/lib/environment/items/lighting/lit-sconce.c", "east");
    addItem("/lib/environment/items/furniture/bench.c", "west");
    addExit("down", "/areas/eledhel/central-city/triumvirate-temple/0x1.c");
}

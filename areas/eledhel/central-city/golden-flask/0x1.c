//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/hallway.c");
    setShortDescription("The guest passage above the Golden Flask");
    addItem("/lib/environment/items/furniture/bench.c", "west");
    addExit("north", "/areas/eledhel/central-city/golden-flask/0x0.c");
    addExit("east", "/areas/eledhel/central-city/golden-flask/1x1.c");
}

//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/hallway.c");
    setShortDescription("The descending passage beneath the temple");
    addItem("/lib/environment/items/lighting/lit-sconce.c", "north");
    addExit("up", "/areas/eledhel/central-city/triumvirate-temple/0x0.c");
    addExit("south", "/areas/eledhel/central-city/triumvirate-temple/1x1.c");
    addExit("down", "/areas/eledhel/under-city/werric-branch/13x6.c");
}

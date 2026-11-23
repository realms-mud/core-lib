//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

public void Setup()
{
    setInterior("/lib/environment/interiors/workshop.c");
    setShortDescription("The armorer's fitting room and repair bench");
    addItem("/lib/environment/items/furniture/workbench.c", "north");
    addItem("/lib/environment/items/furniture/chair.c", "west");
    addExit("west", "/areas/eledhel/central-city/old-city-armorer/0x0.c");
}

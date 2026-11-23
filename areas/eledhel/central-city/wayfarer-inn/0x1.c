//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

public void Setup()
{
    setInterior("/lib/environment/interiors/hallway.c");
    setShortDescription("A quiet upstairs passage above the common room");
    addItem("/lib/environment/items/furniture/bench.c", "west");
    addExit("west", "/areas/eledhel/central-city/wayfarer-inn/0x0.c");
    addExit("east", "/areas/eledhel/central-city/wayfarer-inn/1x1.c");
}

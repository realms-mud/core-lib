//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

public void Setup()
{
    setInterior("/lib/environment/interiors/hallway.c");
    setShortDescription("A compact stage and several rows of benches "
        "make room for neighborhood performances.");
    addItem("/lib/environment/items/furniture/bench.c", "north");
    addItem("/lib/environment/items/furniture/bench.c", "south");
    addObject("/areas/eledhel/central-city/characters/theater-manager.c");
    addObject("/areas/eledhel/central-city/characters/theater-performer.c");
    addExit("south", "/areas/eledhel/central-city/theater/0x0.c");
}

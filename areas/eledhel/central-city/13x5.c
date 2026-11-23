//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/plaza.c");

    addDecorator("road intersection");
    addItem("/lib/environment/items/furniture/bench.c", "north");
    addItem("/lib/environment/items/furniture/bench.c", "south");
    addItem("/lib/environment/items/objects/notice-board.c", "west");
    addObject("/areas/eledhel/central-city/characters/city-crier.c");

    addExit("north", "/areas/eledhel/central-city/13x6.c");
    addExit("south", "/areas/eledhel/central-city/13x4.c");
    addExit("west", "/areas/eledhel/central-city/12x5.c");
    addExit("east", "/areas/eledhel/central-city/14x5.c");
}

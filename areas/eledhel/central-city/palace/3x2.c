//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-clearing.c");
    addFeature("/lib/environment/features/water/pond.c", "north");
    addItem("/lib/environment/items/furniture/bench.c", "west");
    addDecorator("palace south garden 0x2");

    addExit("north", "/areas/eledhel/central-city/palace/3x1.c");
    addExit("east", "/areas/eledhel/central-city/palace/4x2.c");
    addExit("west", "/areas/eledhel/central-city/palace/2x2.c");
    addExit("south", "/areas/eledhel/central-city/palace/3x3.c");
}

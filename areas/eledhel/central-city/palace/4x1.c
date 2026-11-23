//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-clearing.c");
    addFeature("/lib/environment/features/vegetation/ash-coppice.c",
        "north");
    addItem("/lib/environment/items/furniture/bench.c", "south");
    addDecorator("palace south garden 2x0");

    addExit("west", "/areas/eledhel/central-city/palace/3x1.c");
    addExit("south", "/areas/eledhel/central-city/palace/4x2.c");
}

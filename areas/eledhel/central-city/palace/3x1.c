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
    addItem("/lib/environment/items/objects/flower-box.c", "east");
    addDecorator("palace south garden 1x0");

    addExit("west", "/areas/eledhel/central-city/palace/2x1.c");
    addExit("east", "/areas/eledhel/central-city/palace/4x1.c");
    addExit("south", "/areas/eledhel/central-city/palace/3x2.c");
}

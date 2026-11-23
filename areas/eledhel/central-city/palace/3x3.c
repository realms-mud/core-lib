//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "west");
    addItem("/lib/environment/items/furniture/window-seat.c", "east");
    addDecorator("palace interior");

    addExit("north", "/areas/eledhel/central-city/palace/3x2.c");
    addExit("east", "/areas/eledhel/central-city/palace/4x3.c");
    addExit("west", "/areas/eledhel/central-city/palace/2x3.c");
}

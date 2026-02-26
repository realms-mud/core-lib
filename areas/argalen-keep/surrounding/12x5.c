//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/village.c");
    addBuilding("/lib/environment/buildings/shops/inn.c", "west");
    addBuilding("/lib/environment/buildings/trades/market.c", "east");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "south");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "north");
    addItem("/lib/environment/items/lighting/lantern.c", "north");
    addItem("/lib/environment/items/lighting/lantern.c", "south");
    addItem("/lib/environment/items/furniture/bench.c", "east");

    addDecorator("village square");

    addExit("south", "/areas/argalen-keep/surrounding/12x4.c");
    addExit("north", "/areas/argalen-keep/surrounding/12x6.c");
    addExit("west", "/areas/argalen-keep/surrounding/11x5.c");
    addExit("east", "/areas/argalen-keep/surrounding/13x5.c");
}

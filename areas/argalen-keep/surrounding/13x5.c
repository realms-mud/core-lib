//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/village.c");
    addBuilding("/lib/environment/buildings/trades/market.c", "south");
    addBuilding("/lib/environment/buildings/shops/grocer.c", "east",
        "/areas/argalen-keep/surrounding/13x6.c");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "west");
    addItem("/lib/environment/items/lighting/lantern.c", "east");

    addDecorator("village east-west road");

    addExit("west", "/areas/argalen-keep/surrounding/12x5.c");
}

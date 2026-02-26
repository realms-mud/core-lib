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
    addBuilding("/lib/environment/buildings/shops/grocer.c", "north",
        "/areas/argalen-keep/surrounding/market/0x0.c");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "west");
    addItem("/lib/environment/items/lighting/lantern.c", "south");

    addDecorator("village east-west road");

    addExit("west", "/areas/argalen-keep/surrounding/12x5.c");
}

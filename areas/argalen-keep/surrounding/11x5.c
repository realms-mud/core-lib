//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/village.c");
    addBuilding("/lib/environment/buildings/shops/inn.c", "north",
        "/areas/argalen-keep/surrounding/inn/0x0.c");
    addBuilding("/lib/environment/buildings/shops/bakery.c", "south");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "east");
    addItem("/lib/environment/items/lighting/lantern.c", "north");

    addDecorator("village east-west road");

    addExit("east", "/areas/argalen-keep/surrounding/12x5.c");
}

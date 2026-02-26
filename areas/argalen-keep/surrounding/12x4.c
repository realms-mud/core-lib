//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/village.c");
    addBuilding("/lib/environment/buildings/homes/wooden-house.c", "west");
    addBuilding("/lib/environment/buildings/shops/blacksmith.c", "east",
        "/areas/argalen-keep/surrounding/blacksmith/0x0.c");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "north");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "south");
    addItem("/lib/environment/items/lighting/lantern.c", "east");

    addDecorator("village north-south road");

    addExit("south", "/areas/argalen-keep/surrounding/12x3.c");
    addExit("north", "/areas/argalen-keep/surrounding/12x5.c");
}

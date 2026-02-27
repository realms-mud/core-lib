//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    addBuilding("/lib/environment/buildings/homes/farm-house.c", "west");
    addBuilding("/lib/environment/buildings/trades/stable.c", "east");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "north");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "south");
    addFeature("/lib/environment/features/trees/apple-stand.c", "southwest");

    addDecorator("village north-south road");

    addExit("south", "/areas/argalen-keep/surrounding/12x2.c");
    addExit("north", "/areas/argalen-keep/surrounding/12x4.c");
    addExit("west", "/areas/argalen-keep/surrounding/10x3.c");
    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addExit("east", "/areas/argalen-keep/surrounding/14x3.c");
    addFeature("/lib/environment/features/paths/trail.c", "east");
}

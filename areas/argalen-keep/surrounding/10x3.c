//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    addFeature("/lib/environment/features/trees/walnut-stand.c", "west");
    addFeature("/lib/environment/features/landforms/dale.c", "south");
    addBuilding("/lib/environment/buildings/homes/farm-house.c", "north");
    addBuilding("/lib/environment/buildings/trades/barn.c", "southwest");

    addExit("east", "/areas/argalen-keep/surrounding/12x3.c");
    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addExit("west", "/areas/argalen-keep/surrounding/9x3.c");
    addFeature("/lib/environment/features/paths/trail.c", "west");
}

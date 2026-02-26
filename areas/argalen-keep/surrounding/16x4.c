//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-hill.c");
    addFeature("/lib/environment/features/landforms/cliff.c", "east");
    addFeature("/lib/environment/features/trees/pine-stand.c", "south");
    addBuilding("/lib/environment/buildings/trades/mining-company.c", "north");

    addExit("west", "/areas/argalen-keep/surrounding/15x4.c");
    addFeature("/lib/environment/features/paths/trail.c", "west");
}

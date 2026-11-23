//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    addObject("/areas/eledhel/southern-city/characters/streets/"
        "halwen.c");
    setTerrain("/lib/environment/terrain/city.c");
    addBuilding("/lib/environment/buildings/military/gate-house.c", 
        "north", "/areas/eledhel/southern-city/12x1.c");
    addBuilding("/lib/environment/buildings/military/tall-wall-tower.c", 
        "west");
    addBuilding("/lib/environment/buildings/military/tall-wall-tower.c", 
        "east");

    addExit("south", "/areas/eledhel/southern-rural/3x9.c");
}

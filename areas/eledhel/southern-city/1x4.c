//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addBuilding("/lib/environment/buildings/military/tall-stone-wall.c",
        "west");
    addBuilding("/lib/environment/buildings/homes/large-ornate-house.c", 
        "east", "/areas/eledhel/southern-city/thuenach/0x3.c");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "north");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "south");

    addDecorator("inner north-south wall");

    addExit("north", "/areas/eledhel/southern-city/1x5.c");
    addExit("south", "/areas/eledhel/southern-city/1x3.c");
}

//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addBuilding("/lib/environment/buildings/military/tall-stone-wall.c",
        "west");
    addBuilding("/lib/environment/buildings/homes/manor.c", "east",
        "/lib/tutorial/eledhel/southern-city/hrongar/0x3.c");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "north");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "south");
    addFeature("/lib/environment/features/paths/entry-path.c", "east");

    addDecorator("inner north-south wall");

    addExit("north", "/lib/tutorial/eledhel/southern-city/1x4.c");
    addExit("south", "/lib/tutorial/eledhel/southern-city/1x2.c");
}

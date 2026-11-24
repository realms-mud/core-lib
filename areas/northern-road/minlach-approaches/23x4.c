//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addFeature("/lib/environment/features/agriculture/fieldstone-wall.c",
        "north");
    addItem("/lib/environment/items/military/supply-crate.c", "west");
    addDecorator("village road T-south");

    addExit("west", "/areas/northern-road/minlach-approaches/22x4.c");
    addExit("east", "/areas/northern-road/minlach-approaches/24x4.c");
    addExit("south", "/areas/northern-road/minlach-approaches/23x5.c");
}

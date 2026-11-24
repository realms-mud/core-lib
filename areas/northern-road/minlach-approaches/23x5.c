//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/plains.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addFeature("/lib/environment/features/agriculture/fieldstone-wall.c",
        "east");
    addItem("/lib/environment/items/military/supply-crate.c", "north");
    addItem("/lib/environment/items/marine/coiled-rope.c", "west");
    addDecorator("village north-south road");

    addExit("north", "/areas/northern-road/minlach-approaches/23x4.c");
    addExit("south", "/areas/northern-road/minlach-approaches/23x6.c");
}

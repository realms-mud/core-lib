//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/plains.c");
    addFeature("/lib/environment/features/agriculture/fieldstone-wall.c",
        "east");
    addItem("/lib/environment/items/marine/harbor-lantern.c", "south");
    addItem("/lib/environment/items/marine/coiled-rope.c", "west");
    addItem("/lib/environment/items/military/supply-crate.c", "north");
    addDecorator("village market");

    addObject(
        "/areas/northern-road/minlach-approaches/characters/dulin-hadrik.c");
    addExit("north", "/areas/northern-road/minlach-approaches/23x5.c");
}

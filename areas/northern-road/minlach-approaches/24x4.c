//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/plains.c");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "east");
    addFeature("/lib/environment/features/agriculture/fieldstone-wall.c",
        "north");
    addItem("/lib/environment/items/objects/boundary-stone.c", "southwest");
    addItem("/lib/environment/items/marine/harbor-lantern.c", "northwest");
    addDecorator("village east-west road");

    addExit("west", "/areas/northern-road/minlach-approaches/23x4.c");
    addExit("east", "/areas/minlach/1x0.c");
}

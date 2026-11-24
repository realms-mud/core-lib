//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/plants/common-pulse-rows.c",
        "north");
    addFeature("/lib/environment/features/water/field-drain.c", "south");
    addItem("/lib/environment/items/objects/boundary-stone.c", "west");
    addDecorator("village east-west road");

    addExit("west", "/areas/northern-road/minlach-approaches/12x4.c");
    addExit("east", "/areas/northern-road/minlach-approaches/14x4.c");
}

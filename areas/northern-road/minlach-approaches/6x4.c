//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/water/river-with-bridge.c",
        "north");
    addFeature("/lib/environment/features/plants/rye-field.c", "south");
    addItem("/lib/environment/items/objects/rope-bundle.c", "west");
    addDecorator("village east-west road");

    addExit("west", "/areas/northern-road/minlach-approaches/5x4.c");
    addExit("east", "/areas/northern-road/minlach-approaches/7x4.c");
}

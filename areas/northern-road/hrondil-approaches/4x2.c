//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addFeature("/lib/environment/features/water/field-drain.c", "south");
    addItem("/lib/environment/items/objects/hand-cart.c", "southwest");
    addFeature("/lib/environment/features/plants/common-root-beds.c",
        "north");

    addDecorator("village east-west road");

    addExit("east", "/areas/northern-road/hrondil-approaches/5x2.c");
    addExit("west", "/areas/northern-road/hrondil-approaches/3x2.c");
}

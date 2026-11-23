//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "north");
    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addFeature("/lib/environment/features/water/field-drain.c", "east");
    addItem("/lib/environment/items/objects/signPost.c", "northeast");
    addItem("/lib/environment/items/objects/hand-cart.c", "south");

    addDecorator("village road corner NW");

    addExit("north",
        "/areas/northern-road/north-gate/market-gardens/2x4.c");
    addExit("west", "/areas/northern-road/north-gate/11x5.c");
}

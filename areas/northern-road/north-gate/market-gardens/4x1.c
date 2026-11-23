//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "north");
    addFeature("/lib/environment/features/paths/dirt-road.c", "south");
    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addFeature("/lib/environment/features/plants/common-root-beds.c",
        "east");
    addItem("/lib/environment/items/objects/wooden-fence.c", "south");

    addDecorator("village road T-west");

    addExit("north", "/areas/northern-road/north-gate/market-gardens/4x0.c");
    addExit("south", "/areas/northern-road/north-gate/market-gardens/4x2.c");
    addExit("west", "/areas/northern-road/north-gate/market-gardens/3x1.c");
}

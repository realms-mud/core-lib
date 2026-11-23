//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "north");
    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addItem("/lib/environment/items/objects/wooden-fence.c", "south");

    addDecorator("village road corner NE");

    addExit("north", "/areas/northern-road/north-gate/market-gardens/0x3.c");
    addExit("east", "/areas/northern-road/north-gate/market-gardens/1x4.c");
}

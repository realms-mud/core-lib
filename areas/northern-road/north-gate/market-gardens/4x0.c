//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "south");
    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addItem("/lib/environment/items/objects/wooden-fence.c", "north");

    addDecorator("village road corner SW");

    addExit("south", "/areas/northern-road/north-gate/market-gardens/4x1.c");
    addExit("west", "/areas/northern-road/north-gate/market-gardens/3x0.c");
}

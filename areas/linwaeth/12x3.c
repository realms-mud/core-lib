//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    setShortDescription("Linwaeth market square");
    addDecorator("village square");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "north");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "south");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "east");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "west");
    addItem("/lib/environment/items/objects/market-stall.c", "east");
    addExit("north", "/areas/linwaeth/12x2.c");
    addExit("south", "/areas/linwaeth/12x4.c");
    addExit("east", "/areas/linwaeth/13x3.c");
    addExit("west", "/areas/linwaeth/11x3.c");
}

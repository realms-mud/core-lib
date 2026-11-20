//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    setShortDescription("The south market crossing");
    addDecorator("village road intersection");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "north");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "south");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "east");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "west");
    addExit("north", "/areas/linwaeth/12x4.c");
    addExit("south", "/areas/linwaeth/12x6.c");
    addExit("east", "/areas/linwaeth/13x5.c");
    addExit("west", "/areas/linwaeth/11x5.c");
}

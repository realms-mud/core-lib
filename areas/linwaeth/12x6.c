//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    setShortDescription("Linwaeth's southern gate");
    addDecorator("village north-south road");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "north");
    addFeature("/lib/environment/features/paths/road.c", "south");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "east");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "west");
    addExit("north", "/areas/linwaeth/12x5.c");
    addExit("south", "/areas/linwaeth/12x7.c");
    addExit("east", "/areas/linwaeth/13x6.c");
    addExit("west", "/areas/linwaeth/11x6.c");
}

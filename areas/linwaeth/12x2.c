//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    setShortDescription("The north market approach");
    addDecorator("village road intersection");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "north");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "south");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "east");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "west");
    addExit("north", "/areas/linwaeth/12x1.c");
    addExit("south", "/areas/linwaeth/12x3.c");
    addExit("east", "/areas/linwaeth/13x2.c");
    addExit("west", "/areas/linwaeth/11x2.c");
}

//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    setShortDescription("The southern road beyond the wall");
    addDecorator("village north-south road");
    addFeature("/lib/environment/features/paths/road.c", "north");
    addFeature("/lib/environment/features/paths/road.c", "south");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("north", "/areas/linwaeth/12x6.c");
    addExit("south", "/areas/linwaeth/12x8.c");
    addExit("east", "/areas/linwaeth/13x7.c");
    addExit("west", "/areas/linwaeth/11x7.c");
}

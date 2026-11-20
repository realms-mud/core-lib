//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    setShortDescription("The southern field waymarker");
    addDecorator("village north-south road");
    addFeature("/lib/environment/features/paths/road.c", "north");
    addFeature("/lib/environment/features/paths/road.c", "south");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("north", "/areas/linwaeth/12x7.c");
    addExit("south", "/areas/linwaeth/12x9.c");
    addExit("west", "/areas/linwaeth/11x8.c");
}

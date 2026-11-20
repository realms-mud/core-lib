//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/village.c");
    setShortDescription("The north gate road enters Linwaeth");
    addDecorator("village road T-west");
    addFeature("/lib/environment/features/paths/road.c", "north");
    addFeature("/lib/environment/features/paths/road.c", "west");
    addFeature("/lib/environment/features/paths/road.c", "south");
    addExit("west", "/areas/eledhel/southwest-rural-five/13x9.c");
    addExit("north", "/areas/eledhel/southwest-rural-five/14x8.c");
    addExit("south", "/areas/eledhel/south-rural-route-13/0x2.c");
}

//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/meadow.c");
    setShortDescription("A track leads west to a drovers' rest yard");
    addDecorator("village road T-west");
    addFeature("/lib/environment/features/paths/road.c", "north");
    addFeature("/lib/environment/features/paths/road.c", "south");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("north", "/areas/eledhel/southwest-rural-four/12x2.c");
    addExit("south", "/areas/eledhel/southwest-rural-four/12x4.c");
    addExit("west", "/areas/eledhel/southwest-rural-four/11x3.c");
}

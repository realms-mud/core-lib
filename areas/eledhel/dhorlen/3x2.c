//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    setShortDescription("The ford green at Dhorlen's old crossing");
    addDecorator("village road intersection");
    addFeature("/lib/environment/features/paths/road.c", "north");
    addFeature("/lib/environment/features/paths/road.c", "south");
    addFeature("/lib/environment/features/paths/road.c", "east");
    addFeature("/lib/environment/features/paths/road.c", "west");
    addExit("north", "/areas/eledhel/dhorlen/3x1.c");
    addExit("south", "/areas/eledhel/dhorlen/3x3.c");
    addExit("east", "/areas/eledhel/dhorlen/4x2.c");
    addExit("west", "/areas/eledhel/dhorlen/2x2.c");
}

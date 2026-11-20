//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/meadow.c");
    setShortDescription("A cart track turns toward a distant homestead");
    addDecorator("village road T-west");
    addFeature("/lib/environment/features/paths/road.c", "north");
    addFeature("/lib/environment/features/paths/road.c", "south");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("north", "/areas/eledhel/south-coast-one/12x5.c");
    addExit("south", "/areas/eledhel/south-coast-one/12x7.c");
    addExit("west", "/areas/eledhel/south-coast-one/11x6.c");
}

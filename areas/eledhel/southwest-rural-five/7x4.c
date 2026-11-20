//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/plains.c");
    setShortDescription("A path leaves the road for the wool-sorting sheds");
    addDecorator("village road T-north");
    addFeature("/lib/environment/features/paths/road.c", "west");
    addFeature("/lib/environment/features/paths/road.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("west", "/areas/eledhel/southwest-rural-five/6x4.c");
    addExit("east", "/areas/eledhel/southwest-rural-five/8x4.c");
    addExit("north", "/areas/eledhel/southwest-rural-five/7x3.c");
}

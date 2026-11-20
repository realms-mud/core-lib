//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/plains.c");
    setShortDescription("A farm track leads north from the King's Road");
    addDecorator("village road T-north");
    addFeature("/lib/environment/features/paths/road.c", "west");
    addFeature("/lib/environment/features/paths/road.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("west", "/areas/eledhel/southwest-rural-five/3x4.c");
    addExit("east", "/areas/eledhel/southwest-rural-five/5x4.c");
    addExit("north", "/areas/eledhel/southwest-rural-five/4x3.c");
}

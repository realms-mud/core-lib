//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/plains.c");
    setShortDescription("The road turns south toward Linwaeth's gate");
    addDecorator("village road T-south");
    addFeature("/lib/environment/features/paths/road.c", "west");
    addFeature("/lib/environment/features/paths/road.c", "south");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("west", "/areas/eledhel/southwest-rural-five/11x4.c");
    addExit("south", "/areas/eledhel/southwest-rural-five/12x5.c");
    addExit("east", "/areas/eledhel/southwest-rural-five/13x4.c");
}

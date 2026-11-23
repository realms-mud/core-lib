//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-clearing.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "north");
    addFeature("/lib/environment/features/paths/dirt-road.c", "south");
    addFeature("/lib/environment/features/trees/beech-stand.c", "east");
    addFeature("/lib/environment/features/water/spring.c", "west");

    addDecorator("village north-south road");

    addExit("north", "/areas/northern-road/hrondil-approaches/24x4.c");
    addExit("south", "/areas/northern-road/hrondil-approaches/24x6.c");
}

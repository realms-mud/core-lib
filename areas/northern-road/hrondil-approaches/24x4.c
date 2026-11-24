//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-clearing.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addFeature("/lib/environment/features/paths/dirt-road.c", "south");
    addFeature("/lib/environment/features/trees/spruce-stand.c", "north");
    addFeature("/lib/environment/features/water/brook.c", "east");

    addDecorator("village road T-south");

    addExit("west", "/areas/northern-road/hrondil-approaches/23x4.c");
    addExit("south", "/areas/northern-road/hrondil-approaches/24x5.c");
    addExit("east", "/areas/tol-dhurath/northern-trail/0x4.c");
}

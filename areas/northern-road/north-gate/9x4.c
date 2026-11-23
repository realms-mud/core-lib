//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-clearing.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "south");
    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addFeature("/lib/environment/features/trees/alder-stand.c", "north");
    addFeature("/lib/environment/features/plants/blackberry-bramble.c",
        "east");

    addDecorator("village road corner SW");

    addExit("south", "/areas/northern-road/north-gate/9x5.c");
    addExit("west", "/areas/northern-road/north-gate/8x4.c");
}

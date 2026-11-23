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
    addFeature("/lib/environment/features/trees/willow-stand.c", "east");
    addFeature("/lib/environment/features/water/stream.c", "west");

    addDecorator("village north-south road");

    addExit("north", "/areas/northern-road/belathon-eolach/0x6.c");
    addExit("south", "/areas/northern-road/belathon-eolach/0x8.c");
}

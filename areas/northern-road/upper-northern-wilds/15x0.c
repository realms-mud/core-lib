//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/rocky-shoreline.c");
    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addFeature("/lib/environment/features/water/tidal-pool.c", "north");
    addFeature("/lib/environment/features/landforms/bluff.c", "south");
    addDecorator("village east-west road");
    addExit("east", "/areas/northern-road/upper-northern-wilds/16x0.c");
    addExit("west", "/areas/northern-road/upper-northern-wilds/14x0.c");
}

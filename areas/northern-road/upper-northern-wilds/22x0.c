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
    addFeature("/lib/environment/features/water/rocky-sea-shore.c", "north");
    addFeature("/lib/environment/features/water/tidal-pool.c", "south");
    addDecorator("village east-west road");
    addExit("east", "/areas/northern-road/upper-northern-wilds/23x0.c");
    addExit("west", "/areas/northern-road/upper-northern-wilds/21x0.c");
}

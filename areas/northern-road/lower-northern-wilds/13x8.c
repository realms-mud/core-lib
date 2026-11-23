//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/rocky-mountain.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addFeature("/lib/environment/features/water/stream.c", "south");
    addFeature("/lib/environment/features/landforms/tor.c", "north");

    addDecorator("village east-west road");

    addExit("east", "/areas/northern-road/lower-northern-wilds/14x8.c");
    addExit("west", "/areas/northern-road/lower-northern-wilds/12x8.c");
}

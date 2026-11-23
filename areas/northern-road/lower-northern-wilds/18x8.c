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
    addFeature("/lib/environment/features/landforms/crag.c", "south");
    addFeature("/lib/environment/features/ruins/relay-tower.c", "north");
    addExit("down", "/areas/northern-road/lower-northern-wilds/relay-tower/cellar.c");

    addDecorator("village east-west road");

    addExit("east", "/areas/northern-road/lower-northern-wilds/19x8.c");
    addExit("west", "/areas/northern-road/lower-northern-wilds/17x8.c");
}

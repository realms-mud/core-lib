//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "north");
    addFeature("/lib/environment/features/paths/dirt-road.c", "south");
    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addFeature("/lib/environment/features/trees/alder-stand.c", "east");
    addFeature("/lib/environment/features/plants/blackberry-bramble.c",
        "southwest");
    addItem("/lib/environment/items/objects/fox-tracks.c", "southeast");

    addDecorator("village road T-west");

    addExit("north", "/areas/northern-road/gundil-coast/0x0.c");
    addExit("south", "/areas/northern-road/north-gate/9x9.c");
    addExit("west", "/areas/northern-road/north-gate/8x8.c");
}

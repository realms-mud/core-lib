//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addFeature("/lib/environment/features/trees/birch-stand.c", "north");
    addFeature("/lib/environment/features/plants/blackberry-bramble.c",
        "south");
    addItem("/lib/environment/items/objects/fox-tracks.c", "northwest");

    addDecorator("village east-west road");

    addExit("east", "/areas/northern-road/north-gate/9x8.c");
    addExit("west", "/areas/northern-road/north-gate/7x8.c");
}

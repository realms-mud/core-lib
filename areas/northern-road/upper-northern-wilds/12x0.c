//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-clearing.c");
    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addFeature("/lib/environment/features/trees/birch-stand.c", "north");
    addFeature("/lib/environment/features/water/stream.c", "south");
    addItem("/lib/environment/items/objects/fox-tracks.c", "southeast");
    addDecorator("village east-west road");
    addExit("east", "/areas/northern-road/upper-northern-wilds/13x0.c");
    addExit("west", "/areas/northern-road/upper-northern-wilds/11x0.c");
}

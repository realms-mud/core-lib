//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-clearing.c");
    addFeature("/lib/environment/features/water/stream.c", "west");
    addFeature("/lib/environment/features/trees/birch-stand.c", "east");
    addItem("/lib/environment/items/objects/fox-tracks.c", "northwest");
    addExit("west",
        "/areas/northern-road/upper-northern-wilds/bridge/ford.c");
    addExit("north", "/areas/northern-road/upper-northern-wilds/13x0.c");
}

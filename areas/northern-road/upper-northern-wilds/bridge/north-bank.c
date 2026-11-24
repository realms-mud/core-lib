//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-clearing.c");
    addFeature("/lib/environment/features/water/stream.c", "east");
    addFeature("/lib/environment/features/trees/oak-stand.c", "west");
    addItem("/lib/environment/items/objects/boundary-stone.c", "north");
    addExit("north", "/areas/northern-road/upper-northern-wilds/12x0.c");
    addExit("east",
        "/areas/northern-road/upper-northern-wilds/bridge/broken-span.c");
    addExit("south",
        "/areas/northern-road/upper-northern-wilds/bridge/ford.c");
}

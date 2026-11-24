//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/rocky-shoreline.c");
    addFeature("/lib/environment/features/water/rocky-sea-shore.c", "south");
    addFeature("/lib/environment/features/water/tidal-pool.c", "east");
    addItem("/lib/environment/items/marine/torn-fishing-net.c", "west");
    addItem("/lib/environment/items/marine/coiled-rope.c", "north");
    addExit("north",
        "/areas/northern-road/upper-northern-wilds/fishery/boat-shed.c");
    addExit("west",
        "/areas/northern-road/upper-northern-wilds/fishery/smokehouse.c");
}

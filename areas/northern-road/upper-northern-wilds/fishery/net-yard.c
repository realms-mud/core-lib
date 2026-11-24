//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/rocky-shoreline.c");
    addFeature("/lib/environment/features/water/rocky-sea-shore.c", "east");
    addItem("/lib/environment/items/marine/fishing-net.c", "north");
    addItem("/lib/environment/items/marine/torn-fishing-net.c", "south");
    addItem("/lib/environment/items/marine/cargo-net.c", "west");
    addExit("west",
        "/areas/northern-road/upper-northern-wilds/fishery/landing.c");
    addExit("east",
        "/areas/northern-road/upper-northern-wilds/fishery/boat-shed.c");
    addExit("south",
        "/areas/northern-road/upper-northern-wilds/fishery/smokehouse.c");
}

//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/rocky-shoreline.c");
    addFeature("/lib/environment/features/water/rocky-sea-shore.c", "south");
    addItem("/lib/environment/items/marine/fishing-hut.c", "west");
    addItem("/lib/environment/items/marine/crate-of-fish.c", "east");
    addObject(
        "/areas/northern-road/upper-northern-wilds/characters/sairen-drel.c");
    addExit("north", "/areas/northern-road/upper-northern-wilds/15x0.c");
    addExit("east",
        "/areas/northern-road/upper-northern-wilds/fishery/net-yard.c");
    addExit("south",
        "/areas/northern-road/upper-northern-wilds/fishery/tide-cave.c");
}

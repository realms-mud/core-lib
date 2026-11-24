//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/rocky-shoreline.c");
    addFeature("/lib/environment/features/water/rocky-sea-shore.c", "east");
    addItem("/lib/environment/items/marine/rowboat.c", "north");
    addItem("/lib/environment/items/marine/boat-ramp.c", "south");
    addItem("/lib/environment/items/marine/coiled-rope.c", "west");
    addObject(
        "/areas/northern-road/upper-northern-wilds/characters/ilden-marr.c");
    addExit("west",
        "/areas/northern-road/upper-northern-wilds/fishery/net-yard.c");
    addExit("south",
        "/areas/northern-road/upper-northern-wilds/fishery/ebb-rocks.c");
}

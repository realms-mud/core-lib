//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/rocky-shoreline.c");
    addFeature("/lib/environment/features/cave.c", "north");
    addFeature("/lib/environment/features/water/tidal-pool.c", "east");
    addItem("/lib/environment/items/marine/torn-fishing-net.c", "west");
    setEncounterLevel(5);
    addRandomCreature(({ "otter", "raccoon" }));
    addExit("north",
        "/areas/northern-road/upper-northern-wilds/fishery/landing.c");
    addExit("east",
        "/areas/northern-road/upper-northern-wilds/fishery/smokehouse.c");
}

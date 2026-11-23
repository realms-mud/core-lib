//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-mountain.c");
    addFeature("/lib/environment/features/trees/spruce-stand.c", "north");
    addItem("/lib/environment/items/military/small-barricade.c", "south");
    addItem("/lib/environment/items/military/supply-crate.c", "west");
    addObject("/areas/northern-road/upper-northern-wilds/characters/phaedra-sentry.c");

    addExit("south", "/areas/northern-road/upper-northern-wilds/0x0.c");
    addExit("north", "/areas/northern-road/upper-northern-wilds/phaedra-outpost/gatehouse.c");
    addExit("east", "/areas/northern-road/upper-northern-wilds/phaedra-outpost/drill-yard.c");
    addExit("up", "/areas/northern-road/upper-northern-wilds/phaedra-outpost/lookout.c");
}

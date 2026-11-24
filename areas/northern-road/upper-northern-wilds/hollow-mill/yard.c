//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-clearing.c");
    addFeature("/lib/environment/features/paths/dirt-road.c", "south");
    addFeature("/lib/environment/features/water/stream.c", "east");
    addItem("/lib/environment/items/objects/wheelbarrow.c", "west");
    addItem("/lib/environment/items/crafts/flour-sack.c", "northwest");
    addObject(
        "/areas/northern-road/upper-northern-wilds/characters/oren-vey.c");
    setEncounterLevel(6);
    addRandomCreature(({ "red fox", "white-tail deer" }));
    addExit("south", "/areas/northern-road/upper-northern-wilds/5x0.c");
    addExit("north",
        "/areas/northern-road/upper-northern-wilds/hollow-mill/grain-store.c");
    addExit("east",
        "/areas/northern-road/upper-northern-wilds/hollow-mill/wheelhouse.c");
}

//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/rocky-mountain.c");
    addFeature("/lib/environment/features/barrow.c", "north");
    addFeature("/lib/environment/features/landforms/knoll.c", "east");
    addItem("/lib/environment/items/objects/stone-pile.c", "west");
    addObject(
        "/areas/northern-road/upper-northern-wilds/characters/eira-pell.c");
    setEncounterLevel(7);
    addRandomCreature(({ "gray wolf", "boar" }));
    addExit("south",
        "/areas/northern-road/upper-northern-wilds/barrow-ridge/approach.c");
    addExit("west",
        "/areas/northern-road/upper-northern-wilds/barrow-ridge/sealed-mound.c");
    addExit("north",
        "/areas/northern-road/upper-northern-wilds/barrow-ridge/north-mound.c");
    addExit("east",
        "/areas/northern-road/upper-northern-wilds/barrow-ridge/opened-mound.c");
}

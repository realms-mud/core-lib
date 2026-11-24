//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/crypt.c");
    addItem("/lib/environment/items/furniture/altar-table.c", "north");
    addItem("/lib/environment/items/objects/stone-pile.c", "west");
    setEncounterLevel(7);
    addRandomCreature(({ "skeleton" }));
    addExit("up",
        "/areas/northern-road/upper-northern-wilds/barrow-ridge/antechamber.c");
}

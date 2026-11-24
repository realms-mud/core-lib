//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/rocky-mountain.c");
    addFeature("/lib/environment/features/barrow.c", "north");
    addItem("/lib/environment/items/objects/stone-pile.c", "west");
    addItem("/lib/environment/items/objects/rope-bundle.c", "east");
    addExit("west",
        "/areas/northern-road/upper-northern-wilds/barrow-ridge/mound-ring.c");
    addExit("down",
        "/areas/northern-road/upper-northern-wilds/barrow-ridge/antechamber.c");
}

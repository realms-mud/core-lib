//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-clearing.c");
    addFeature("/lib/environment/features/trees/fir-stand.c", "north");
    addFeature("/lib/environment/features/paths/gravel-road.c", "east");
    addItem(
        "/lib/environment/items/objects/wrecked-stagecoach.c", "none");
    addItem("/lib/environment/items/objects/broken-cart.c", "west");
    addItem("/lib/environment/items/objects/rope-bundle.c", "south");
    setEncounterLevel(6);
    addRandomCreature(({ "outlaw", "gray wolf" }));
    addExit("north",
        "/areas/northern-road/upper-northern-wilds/inland/fir-shelf.c");
    addExit("south", "/areas/northern-road/upper-northern-wilds/8x0.c");
}

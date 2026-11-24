//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/rocky-shoreline.c");
    addFeature("/lib/environment/features/water/shallow-ford.c", "none");
    addFeature("/lib/environment/features/water/stream.c", "east");
    addItem("/lib/environment/items/objects/boundary-stone.c", "north");
    addRandomCreature(({ "otter", "white-tail deer" }));
    addExit("north",
        "/areas/northern-road/upper-northern-wilds/bridge/north-bank.c");
    addExit("east",
        "/areas/northern-road/upper-northern-wilds/bridge/east-bank.c");
}

//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/rocky-shoreline.c");
    addFeature(
        "/lib/environment/features/water/broken-bridge.c", "north");
    addItem("/lib/environment/items/objects/rope-bundle.c", "west");
    addItem("/lib/environment/items/objects/boundary-stone.c", "east");
    addExit("west",
        "/areas/northern-road/upper-northern-wilds/bridge/north-bank.c");
}

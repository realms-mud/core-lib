//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-clearing.c");
    addFeature("/lib/environment/features/water/stream.c", "east");
    addFeature("/lib/environment/features/landforms/ridge.c", "north");
    addItem("/lib/environment/items/crafts/mill-wheel.c", "east");
    addItem("/lib/environment/items/objects/rope-bundle.c", "west");
    addExit("west",
        "/areas/northern-road/upper-northern-wilds/hollow-mill/yard.c");
    addExit("north",
        "/areas/northern-road/upper-northern-wilds/hollow-mill/wheel-room.c");
}

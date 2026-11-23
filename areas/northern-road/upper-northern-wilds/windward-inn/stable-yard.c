//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-clearing.c");
    addFeature("/lib/environment/features/trees/alder-stand.c", "north");
    addItem("/lib/environment/items/objects/water-trough.c", "west");
    addItem("/lib/environment/items/objects/hay-bale.c", "northwest");
    addItem("/lib/environment/items/furniture/bench.c", "east");

    addExit("north", "/areas/northern-road/upper-northern-wilds/windward-inn/common-room.c");
}

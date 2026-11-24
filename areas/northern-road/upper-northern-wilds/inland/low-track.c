//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-clearing.c");
    addFeature("/lib/environment/features/paths/gravel-road.c", "east");
    addFeature("/lib/environment/features/paths/gravel-road.c", "west");
    addFeature("/lib/environment/features/water/creek.c", "south");
    addFeature("/lib/environment/features/trees/alder-stand.c", "north");
    addItem("/lib/environment/items/objects/boundary-stone.c", "southwest");
    addExit("east",
        "/areas/northern-road/upper-northern-wilds/inland/return-track.c");
    addExit("west",
        "/areas/northern-road/upper-northern-wilds/inland/wind-saddle.c");
}

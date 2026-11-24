//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-clearing.c");
    addFeature("/lib/environment/features/paths/gravel-road.c", "north");
    addFeature("/lib/environment/features/paths/dirt-road.c", "south");
    addFeature("/lib/environment/features/trees/alder-stand.c", "east");
    addItem(
        "/lib/environment/items/objects/muddy-hoofprints.c", "west");
    addExit("north",
        "/areas/northern-road/upper-northern-wilds/inland/return-track.c");
    addExit("south", "/areas/northern-road/upper-northern-wilds/11x0.c");
}

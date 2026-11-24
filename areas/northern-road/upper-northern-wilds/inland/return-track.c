//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-mountain.c");
    addFeature("/lib/environment/features/paths/gravel-road.c", "west");
    addFeature("/lib/environment/features/landforms/knoll.c", "east");
    addFeature("/lib/environment/features/trees/pine-stand.c", "south");
    addItem("/lib/environment/items/objects/boundary-stone.c", "north");
    addExit("west",
        "/areas/northern-road/upper-northern-wilds/inland/low-track.c");
    addExit("south",
        "/areas/northern-road/upper-northern-wilds/inland/return-slope.c");
}

//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/rocky-mountain.c");
    addFeature("/lib/environment/features/landforms/ridge.c", "north");
    addFeature("/lib/environment/features/trees/pine-stand.c", "east");
    addItem("/lib/environment/items/objects/boundary-stone.c", "west");
    addExit("south", "/areas/northern-road/upper-northern-wilds/24x0.c");
    addExit("north",
        "/areas/northern-road/upper-northern-wilds/barrow-ridge/mound-ring.c");
}

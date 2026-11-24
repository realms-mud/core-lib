//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/rocky-mountain.c");
    addFeature("/lib/environment/features/barrow.c", "north");
    addFeature("/lib/environment/features/landforms/knoll.c", "east");
    addItem("/lib/environment/items/objects/stone-pile.c", "west");
    addExit("south",
        "/areas/northern-road/upper-northern-wilds/barrow-ridge/mound-ring.c");
}

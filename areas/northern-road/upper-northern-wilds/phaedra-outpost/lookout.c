//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/rocky-mountain.c");
    addFeature("/lib/environment/features/landforms/precipice.c", "north");
    addItem("/lib/environment/items/military/beacon.c", "east");
    addItem("/lib/environment/items/military/signal-fire.c", "west");
    addItem("/lib/environment/items/objects/boundary-stone.c", "south");
    addExit("down", "/areas/northern-road/upper-northern-wilds/phaedra-outpost/courtyard.c");
}

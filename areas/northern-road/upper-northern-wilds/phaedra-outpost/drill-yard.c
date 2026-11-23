//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-clearing.c");
    addItem("/lib/environment/items/military/training-dummy.c", "north");
    addItem("/lib/environment/items/military/archery-target.c", "east");
    addItem("/lib/environment/items/military/drill-field-marker.c", "south");
    addFeature("/lib/environment/features/landforms/hillock.c", "west");

    addExit("west", "/areas/northern-road/upper-northern-wilds/phaedra-outpost/courtyard.c");
}

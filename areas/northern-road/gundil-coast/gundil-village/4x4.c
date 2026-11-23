//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/rocky-shoreline.c");

    addFeature("/lib/environment/features/paths/gravel-road.c", "north");
    addFeature("/lib/environment/features/paths/gravel-road.c", "west");
    addFeature("/lib/environment/features/water/rocky-sea-shore.c",
        "south");
    addItem("/lib/environment/items/marine/fish-cleaning-table.c");
    addItem("/lib/environment/items/marine/crate-of-fish.c", "east");
    addItem("/lib/environment/items/marine/tide-marker.c", "south");
    addObject(
        "/areas/northern-road/gundil-coast/gundil-village/characters/aereth.c");

    addDecorator("village road corner NW");

    addExit("north", "/areas/northern-road/gundil-coast/gundil-village/4x3.c");
    addExit("west", "/areas/northern-road/gundil-coast/gundil-village/3x4.c");
}

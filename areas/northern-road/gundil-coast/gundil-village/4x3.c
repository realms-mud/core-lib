//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/village.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "north");
    addFeature("/lib/environment/features/paths/dirt-road.c", "south");
    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addItem("/lib/environment/items/marine/fishing-hut.c", "east");
    addObject(
        "/areas/northern-road/gundil-coast/gundil-village/characters/dairen.c");

    addDecorator("village road T-west");

    addExit("north", "/areas/northern-road/gundil-coast/gundil-village/4x2.c");
    addExit("south", "/areas/northern-road/gundil-coast/gundil-village/4x4.c");
    addExit("west", "/areas/northern-road/gundil-coast/gundil-village/3x3.c");
}

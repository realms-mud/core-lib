//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/village.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "north");
    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/paths/dirt-road.c", "south");
    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addItem("/lib/environment/items/objects/well.c", "none");
    addItem("/lib/environment/items/objects/market-stall.c", "north");
    addObject(
        "/areas/northern-road/gundil-coast/gundil-village/characters/calwen.c");

    addDecorator("village square");

    addExit("north", "/areas/northern-road/gundil-coast/gundil-village/2x1.c");
    addExit("east", "/areas/northern-road/gundil-coast/gundil-village/3x2.c");
    addExit("south", "/areas/northern-road/gundil-coast/gundil-village/2x3.c");
    addExit("west", "/areas/northern-road/gundil-coast/gundil-village/1x2.c");
}

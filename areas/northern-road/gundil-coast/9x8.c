//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/rocky-shoreline.c");

    addFeature("/lib/environment/features/paths/gravel-road.c", "north");
    addFeature("/lib/environment/features/paths/gravel-road.c", "east");
    addFeature("/lib/environment/features/paths/gravel-road.c", "west");
    addFeature("/lib/environment/features/water/ocean.c", "south");
    addItem("/lib/environment/items/objects/signPost.c", "north");

    addDecorator("village road T-north");

    addExit("north", "/areas/northern-road/northern-manor/0x0.c");
    addExit("east", "/areas/northern-road/gundil-coast/gundil-village/0x2.c");
    addExit("west", "/areas/northern-road/gundil-coast/8x8.c");
}

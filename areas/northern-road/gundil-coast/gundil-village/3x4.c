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
    addFeature("/lib/environment/features/water/rocky-sea-shore.c",
        "south");
    addItem("/lib/environment/items/marine/dock.c", "none");
    addItem("/lib/environment/items/marine/fishing-net.c", "west");

    addDecorator("village road T-north");

    addExit("north", "/areas/northern-road/gundil-coast/gundil-village/3x3.c");
    addExit("east", "/areas/northern-road/gundil-coast/gundil-village/4x4.c");
    addExit("west", "/areas/northern-road/gundil-coast/gundil-village/2x4.c");
}

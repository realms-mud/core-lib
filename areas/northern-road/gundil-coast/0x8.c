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
    addFeature("/lib/environment/features/water/rocky-sea-shore.c",
        "south");

    addDecorator("village road corner NE");

    addExit("north", "/areas/northern-road/gundil-coast/0x7.c");
    addExit("east", "/areas/northern-road/gundil-coast/1x8.c");
}

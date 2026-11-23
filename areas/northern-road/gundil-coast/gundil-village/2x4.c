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
    addFeature("/lib/environment/features/paths/dirt-road.c", "west");

    addDecorator("village road T-north");

    addExit("north", "/areas/northern-road/gundil-coast/gundil-village/2x3.c");
    addExit("east", "/areas/northern-road/gundil-coast/gundil-village/3x4.c");
    addExit("west", "/areas/northern-road/gundil-coast/gundil-village/1x4.c");
}

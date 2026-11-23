//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/village.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/paths/dirt-road.c", "south");
    addFeature("/lib/environment/features/paths/dirt-road.c", "west");

    addDecorator("village road T-south");

    addExit("east", "/areas/northern-road/gundil-coast/gundil-village/2x0.c");
    addExit("south", "/areas/northern-road/gundil-coast/gundil-village/1x1.c");
    addExit("west", "/areas/northern-road/gundil-coast/gundil-village/0x0.c");
}

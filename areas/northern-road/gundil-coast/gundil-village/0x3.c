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

    addDecorator("village road T-east");

    addExit("north", "/areas/northern-road/gundil-coast/gundil-village/0x2.c");
    addExit("east", "/areas/northern-road/gundil-coast/gundil-village/1x3.c");
    addExit("south", "/areas/northern-road/gundil-coast/gundil-village/0x4.c");
}

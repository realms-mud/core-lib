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

    addDecorator("village road corner NE");

    addExit("north", "/areas/northern-road/gundil-coast/gundil-village/0x3.c");
    addExit("east", "/areas/northern-road/gundil-coast/gundil-village/1x4.c");
}

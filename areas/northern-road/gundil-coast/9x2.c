//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-clearing.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "north");
    addFeature("/lib/environment/features/paths/dirt-road.c", "west");

    addDecorator("village road corner NW");

    addExit("north", "/areas/northern-road/gundil-coast/9x1.c");
    addExit("west", "/areas/northern-road/gundil-coast/8x2.c");
}

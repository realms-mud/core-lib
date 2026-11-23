//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addFeature("/lib/environment/features/paths/dirt-road.c", "south");

    addDecorator("village road corner SW");

    addExit("west", "/areas/northern-road/gundil-coast/8x4.c");
    addExit("south", "/areas/northern-road/gundil-coast/9x5.c");
}

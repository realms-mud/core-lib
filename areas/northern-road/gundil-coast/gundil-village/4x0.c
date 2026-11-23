//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/village.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "south");
    addFeature("/lib/environment/features/paths/dirt-road.c", "west");

    addDecorator("village road corner SW");

    addExit("south", "/areas/northern-road/gundil-coast/gundil-village/4x1.c");
    addExit("west", "/areas/northern-road/gundil-coast/gundil-village/3x0.c");
}

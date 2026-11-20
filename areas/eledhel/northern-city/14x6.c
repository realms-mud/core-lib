//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    setShortDescription("The eastern branch of the northern avenue");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "east");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "west");
    addDecorator("east-west road");
    addExit("east", "/areas/eledhel/northern-city/15x6.c");
    addExit("west", "/areas/eledhel/northern-city/13x6.c");
}

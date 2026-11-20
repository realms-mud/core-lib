//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    setShortDescription("The paved approach to Arena Park");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "east");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "west");
    addDecorator("east-west road");
    addExit("east", "/areas/eledhel/northern-city/8x6.c");
    addExit("west", "/areas/eledhel/northern-city/6x6.c");
}

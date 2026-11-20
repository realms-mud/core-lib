//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    setShortDescription("The eastern end of the northern avenue branch");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "west");
    addDecorator("east-west road");
    addExit("west", "/areas/eledhel/northern-city/14x6.c");
}

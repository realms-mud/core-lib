//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");

    addDecorator("north-south road");
    setShortDescription("The northern road leaves the old city for the north ward");
    addObject("/areas/eledhel/central-city/characters/north-road-dispatcher.c");
    addExit("north", "/areas/eledhel/northern-city/12x0.c");
    addExit("south", "/areas/eledhel/central-city/12x8.c");
}

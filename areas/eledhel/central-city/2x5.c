//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    setShortDescription("The paved road continues toward the old city");
    addObject("/areas/eledhel/central-city/characters/city-courier.c");

    addExit("west", "/areas/eledhel/central-city/1x5.c");
    addExit("east", "/areas/eledhel/central-city/3x5.c");
}

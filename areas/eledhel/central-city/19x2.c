//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    setShortDescription("A busy approach to the southern trade street");
    addObject("/areas/eledhel/central-city/characters/market-porter.c");

    addExit("west", "/areas/eledhel/central-city/18x2.c");
    addExit("east", "/areas/eledhel/central-city/20x2.c");
}

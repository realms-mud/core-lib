//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    setShortDescription("A busy stretch of the west road");
    addObject("/areas/eledhel/central-city/characters/wheelwright-apprentice.c");

    addExit("west", "/areas/eledhel/central-city/2x5.c");
    addExit("east", "/areas/eledhel/central-city/4x5.c");
}

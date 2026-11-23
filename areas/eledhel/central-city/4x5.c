//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    setShortDescription("The west road runs between rows of old houses");
    addObject("/areas/eledhel/central-city/characters/bread-carrier.c");

    addExit("west", "/areas/eledhel/central-city/3x5.c");
    addExit("east", "/areas/eledhel/central-city/5x5.c");
}

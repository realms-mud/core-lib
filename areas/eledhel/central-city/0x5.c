//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    setShortDescription("The paved west approach to the old city");
    addObject("/areas/eledhel/central-city/characters/west-approach-porter.c");

    addExit("west", "/areas/eledhel/central-rural/24x5.c");
    addExit("east", "/areas/eledhel/central-city/1x5.c");
}

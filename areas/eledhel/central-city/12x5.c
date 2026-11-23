//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    setShortDescription("The western entrance to the central plaza");
    addObject("/areas/eledhel/central-city/characters/plaza-attendant.c");

    addExit("north", "/areas/eledhel/central-city/12x6.c");
    addExit("south", "/areas/eledhel/central-city/12x4.c");
    addExit("west", "/areas/eledhel/central-city/11x5.c");
    addExit("east", "/areas/eledhel/central-city/13x5.c");
}

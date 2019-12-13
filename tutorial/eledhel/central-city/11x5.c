//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");

    addExit("north", "/lib/tutorial/eledhel/central-city/11x6.c");
    addExit("south", "/lib/tutorial/eledhel/central-city/11x4.c");
    addExit("west", "/lib/tutorial/eledhel/central-city/10x5.c");
    addExit("east", "/lib/tutorial/eledhel/central-city/12x5.c");
}

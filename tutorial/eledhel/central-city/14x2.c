//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");

    addExit("west", "/lib/tutorial/eledhel/central-city/13x2.c");
    addExit("east", "/lib/tutorial/eledhel/central-city/15x2.c");
    addExit("south", "/lib/tutorial/eledhel/central-city/14x1.c");
}

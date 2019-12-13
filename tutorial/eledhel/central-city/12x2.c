//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");

    addExit("east", "/lib/tutorial/eledhel/central-city/13x2.c");
    addExit("north", "/lib/tutorial/eledhel/central-city/12x3.c");
    addExit("south", "/lib/tutorial/eledhel/central-city/12x1.c");
}

//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");

    addExit("west", "/lib/tutorial/eledhel/southern-city/8x2.c");
    addExit("east", "/lib/tutorial/eledhel/southern-city/10x2.c");
    addExit("north", "/lib/tutorial/eledhel/southern-city/9x3.c");
}

//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");

    addExit("east", "/lib/tutorial/eledhel/southern-city/7x5.c");
    addExit("west", "/lib/tutorial/eledhel/southern-city/5x5.c");
    addExit("north", "/lib/tutorial/eledhel/southern-city/6x6.c");
    addExit("south", "/lib/tutorial/eledhel/southern-city/6x4.c");
}

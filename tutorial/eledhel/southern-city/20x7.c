//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");

    addExit("north", "/lib/tutorial/eledhel/southern-city/20x8.c");
    addExit("west", "/lib/tutorial/eledhel/southern-city/19x7.c");
    addExit("east", "/lib/tutorial/eledhel/southern-city/21x7.c");
}

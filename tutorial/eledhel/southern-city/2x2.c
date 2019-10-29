//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");

    addExit("south", "/lib/tutorial/eledhel/southern-city/2x1.c");
    addExit("east", "/lib/tutorial/eledhel/southern-city/3x2.c");
    addExit("west", "/lib/tutorial/eledhel/southern-city/2x2.c");
}

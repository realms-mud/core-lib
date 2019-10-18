//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");

    addDecorator("tall southwest tower");
    addExit("west", "/lib/tutorial/eledhel/southern-city/17x2.c");
    addExit("east", "/lib/tutorial/eledhel/southern-city/19x2.c");
}

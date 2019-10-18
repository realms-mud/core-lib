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
    addExit("north", "/lib/tutorial/eledhel/southern-city/19x3.c");
    addExit("south", "/lib/tutorial/eledhel/southern-city/19x1.c");
    addExit("west", "/lib/tutorial/eledhel/southern-city/11x2.c");
    addExit("east", "/lib/tutorial/eledhel/southern-city/13x2.c");
}

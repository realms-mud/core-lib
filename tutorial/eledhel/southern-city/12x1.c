//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");

    addDecorator("south gate house");
    addExit("north", "/lib/tutorial/eledhel/southern-city/12x2.c");
    addExit("south", "/lib/tutorial/eledhel/southern-city/12x0.c");
}

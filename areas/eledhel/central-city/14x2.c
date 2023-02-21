//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");

    addExit("west", "/areas/eledhel/central-city/13x2.c");
    addExit("east", "/areas/eledhel/central-city/15x2.c");
    addExit("south", "/areas/eledhel/central-city/14x1.c");
}

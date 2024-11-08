//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");

    addExit("east", "/areas/eledhel/central-city/13x2.c");
    addExit("north", "/areas/eledhel/central-city/12x3.c");
    addExit("south", "/areas/eledhel/central-city/12x1.c");
}

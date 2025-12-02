//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addBuilding("/lib/environment/buildings/guilds/scion-of-dhuras.c", "west");

    addExit("north", "/areas/eledhel/southern-city/9x5.c");
    addExit("south", "/areas/eledhel/southern-city/9x3.c");
}

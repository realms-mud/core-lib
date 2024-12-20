//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addBuilding("/lib/environment/buildings/shops/inn.c", "west");

    addExit("north", "/areas/eledhel/southern-city/19x5.c");
    addExit("south", "/areas/eledhel/southern-city/19x3.c");
    addExit("east", "/areas/eledhel/southern-city/20x4.c");
}

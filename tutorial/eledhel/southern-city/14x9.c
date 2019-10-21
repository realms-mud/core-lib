//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addBuilding("/lib/environment/buildings/shops/bowyer.c", "east");

    addExit("north", "/lib/tutorial/eledhel/south-central-city/14x0.c");
    addExit("south", "/lib/tutorial/eledhel/southern-city/14x8.c");
}

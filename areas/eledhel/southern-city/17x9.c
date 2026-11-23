//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addBuildingWithDoor("/lib/environment/buildings/shops/bowyer.c",
        "west", "/areas/eledhel/southern-city/16x9.c",
        "/lib/environment/doors/plank-door.c");
    addBuilding("/lib/environment/buildings/shops/weaponsmith.c",
        "east", "/areas/eledhel/southern-city/axe-and-hammer/0x1.c");

    addExit("north", "/areas/eledhel/central-city/17x0.c");
    addExit("south", "/areas/eledhel/southern-city/17x8.c");
}

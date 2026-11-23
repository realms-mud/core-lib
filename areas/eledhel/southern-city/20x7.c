//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addBuildingWithDoor("/lib/environment/buildings/civic/court-house.c",
        "south", "/areas/eledhel/southern-city/halls-of-justice/0x0.c",
        "/lib/environment/doors/door.c");

    addExit("north", "/areas/eledhel/southern-city/20x8.c");
    addExit("west", "/areas/eledhel/southern-city/19x7.c");
    addExit("east", "/areas/eledhel/southern-city/21x7.c");
}

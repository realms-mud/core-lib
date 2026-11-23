//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    setShortDescription("The Golden Flask stands beside the plaza approach");
    addObject("/areas/eledhel/central-city/characters/inn-guest.c");
    addBuildingWithDoor("/lib/environment/buildings/shops/inn.c",
        "east", "/areas/eledhel/central-city/golden-flask/0x0.c",
        "/lib/environment/doors/plank-door.c");

    addExit("north", "/areas/eledhel/central-city/13x5.c");
    addExit("west", "/areas/eledhel/central-city/12x4.c");
}

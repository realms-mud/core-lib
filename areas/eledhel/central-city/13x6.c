//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    setShortDescription("The street faces the entrance to the Werric temple");
    addObject("/areas/eledhel/central-city/characters/temple-visitor.c");
    addBuildingWithDoor("/lib/environment/buildings/guilds/werric-knight.c",
        "east", "/areas/eledhel/central-city/triumvirate-temple/0x0.c",
        "/lib/environment/doors/plank-door.c");

    addExit("south", "/areas/eledhel/central-city/13x5.c");
    addExit("west", "/areas/eledhel/central-city/12x6.c");
}

//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addBuildingWithDoor("/lib/environment/buildings/guilds/aegis.c",
        "west", "/areas/eledhel/central-city/aegis-hall/0x0.c",
        "/lib/environment/doors/plank-door.c");
    setShortDescription("The street frontage of the Aegis Guard hall");
    addObject("/areas/eledhel/central-city/characters/aegis-messenger.c");

    addExit("north", "/areas/eledhel/central-city/11x5.c");
    addExit("east", "/areas/eledhel/central-city/12x4.c");
}

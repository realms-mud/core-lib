//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    setShortDescription("The tailor's doorway opens onto a narrow street");
    addObject("/areas/eledhel/central-city/characters/tailor-client.c");
    addBuildingWithDoor("/lib/environment/buildings/shops/tailor.c",
        "east", "/areas/eledhel/central-city/old-city-tailor/0x0.c",
        "/lib/environment/doors/plank-door.c");

    addExit("north", "/areas/eledhel/central-city/14x2.c");
    addExit("south", "/areas/eledhel/central-city/14x0.c");
}

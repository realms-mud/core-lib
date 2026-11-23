//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addBuildingWithDoor("/lib/environment/buildings/civic/school-stone.c",
        "west", "/areas/eledhel/central-city/aegis-academy/0x0.c",
        "/lib/environment/doors/plank-door.c");
    setShortDescription("The public approach to the Aegis academy");
    addObject("/areas/eledhel/central-city/characters/academy-cadet.c");

    addExit("south", "/areas/eledhel/central-city/11x5.c");
    addExit("east", "/areas/eledhel/central-city/12x6.c");
}

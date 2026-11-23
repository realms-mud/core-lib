//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    setShortDescription("The public street runs beside the palace facade");
    addObject("/areas/eledhel/central-city/characters/palace-messenger.c");
    addBuilding("/areas/eledhel/central-city/palace-facade.c", "east",
        "/areas/eledhel/central-city/palace/0x2.c");

    addExit("west", "/areas/eledhel/central-city/13x5.c");
}

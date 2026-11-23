//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    setShortDescription("A westward street where rural carts enter the city");
    addObject("/areas/eledhel/central-city/characters/flower-seller.c");

    addExit("west", "/areas/eledhel/central-city/0x5.c");
    addExit("east", "/areas/eledhel/central-city/2x5.c");
}

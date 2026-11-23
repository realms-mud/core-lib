//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    setShortDescription("The broad west avenue crosses the old city");
    addObject("/areas/eledhel/central-city/characters/cart-driver.c");

    addExit("west", "/areas/eledhel/central-city/4x5.c");
    addExit("east", "/areas/eledhel/central-city/6x5.c");
}

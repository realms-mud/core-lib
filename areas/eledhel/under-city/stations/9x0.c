//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/under-city/underCityRoom.c";

public void Setup()
{
    underCityRoom::Setup();
    setShortDescription("The tenth maintenance station has a cistern "
        "pump, spare torches, and a dry place to rest.");
    addItem("/lib/environment/items/furniture/chest.c", "west");
    addItem("/lib/environment/items/lighting/lit-sconce.c", "east");
    addExit("south", "/areas/eledhel/under-city/trunk/99x0.c");
}

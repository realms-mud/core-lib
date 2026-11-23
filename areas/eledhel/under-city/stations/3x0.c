//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/under-city/underCityRoom.c";

public void Setup()
{
    underCityRoom::Setup();
    setShortDescription("A maintenance alcove holds dry kindling, spare "
        "torches, and a hand pump above a shallow cistern.");
    addItem("/lib/environment/items/furniture/chest.c", "west");
    addItem("/lib/environment/items/lighting/lit-sconce.c", "east");
    addExit("south", "/areas/eledhel/under-city/trunk/39x0.c");
}

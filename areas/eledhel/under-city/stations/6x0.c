//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/under-city/underCityRoom.c";

public void Setup()
{
    underCityRoom::Setup();
    setShortDescription("A cistern pump and a bin of dry torches mark "
        "the seventh maintenance station.");
    addItem("/lib/environment/items/furniture/chest.c", "west");
    addItem("/lib/environment/items/lighting/lit-sconce.c", "east");
    addExit("south", "/areas/eledhel/under-city/trunk/69x0.c");
}

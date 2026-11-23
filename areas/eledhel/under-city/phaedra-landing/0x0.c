//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/under-city/underCityRoom.c";

public void Setup()
{
    underCityRoom::Setup();
    setShortDescription("A narrow surgical alcove sits just inside "
        "the hidden map door.");
    addItem("/lib/environment/items/furniture/bed.c", "west");
    addExit("south", "/areas/eledhel/under-city/trunk/2x0.c");
    addExit("north", "/areas/eledhel/under-city/phaedra-mechanism/0x0.c");
}

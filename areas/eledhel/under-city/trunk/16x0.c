//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/under-city/underCityRoom.c";

public void Setup()
{
    underCityRoom::Setup();
    addItem("/lib/environment/items/lighting/lit-sconce.c", "west");
    addExit("west", "/areas/eledhel/under-city/trunk/15x0.c");
    addExit("north", "/areas/eledhel/under-city/naval-branch/0x0.c");
    addExit("east", "/areas/eledhel/under-city/trunk/17x0.c");
}

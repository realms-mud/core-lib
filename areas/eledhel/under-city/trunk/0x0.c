//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/under-city/underCityRoom.c";

public void Setup()
{
    underCityRoom::Setup();
    addItem("/lib/environment/items/lighting/lit-sconce.c", "west");
    addExit("up", "/areas/eledhel/central-city/palace/hidden-passage.c");
    addExit("east", "/areas/eledhel/under-city/trunk/1x0.c");
}

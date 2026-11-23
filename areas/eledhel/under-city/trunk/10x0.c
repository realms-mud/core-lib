//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/under-city/underCityRoom.c";

public void Setup()
{
    underCityRoom::Setup();
    addExit("west", "/areas/eledhel/under-city/trunk/9x0.c");
    addExit("east", "/areas/eledhel/under-city/trunk/11x0.c");
}

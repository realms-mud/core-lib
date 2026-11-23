//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/under-city/underCityRoom.c";

public void Setup()
{
    underCityRoom::Setup();
    addExit("west", "/areas/eledhel/under-city/trunk/4x0.c");
    addExit("north", "/areas/eledhel/under-city/library-branch/0x0.c");
    addExit("east", "/areas/eledhel/under-city/trunk/6x0.c");
}

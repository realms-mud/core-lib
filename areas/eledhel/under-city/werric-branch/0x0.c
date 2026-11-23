//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/under-city/underCityRoom.c";

public void Setup()
{
    underCityRoom::Setup();
    setShortDescription("A quiet flight of steps rises beneath the "
        "old Werric sanctuary.");
    addExit("south", "/areas/eledhel/under-city/trunk/13x0.c");
    addExit("up", "/areas/eledhel/central-city/triumvirate-temple/0x1.c");
}

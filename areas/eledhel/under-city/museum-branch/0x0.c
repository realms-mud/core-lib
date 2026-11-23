//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/under-city/underCityRoom.c";

public void Setup()
{
    underCityRoom::Setup();
    setShortDescription("A short, dust-choked stair rises toward the "
        "foundations of the city museum.");
    addExit("south", "/areas/eledhel/under-city/trunk/8x0.c");
    addExit("up", "/areas/eledhel/northern-city/museum/0x0.c");
}

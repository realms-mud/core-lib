//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/under-city/underCityRoom.c";

public void Setup()
{
    underCityRoom::Setup();
    setShortDescription("A narrow stone stair ends at a concealed panel "
        "beneath the public library.");
    addExit("south", "/areas/eledhel/under-city/trunk/5x0.c");
    addExit("east", "/areas/eledhel/under-city/fox-route/0x0.c");
    addExit("up", "/areas/eledhel/northern-city/library/0x0.c");
}

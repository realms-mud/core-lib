//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/under-city/underCityRoom.c";

public void Setup()
{
    underCityRoom::Setup();
    setShortDescription("A damp stair rises toward the old foundations "
        "of the naval headquarters.");
    addExit("south", "/areas/eledhel/under-city/trunk/16x0.c");
    addExit("up", "/areas/eledhel/northern-city/naval-headquarters/0x0.c");
}

//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/under-city/underCityRoom.c";

public void Setup()
{
    underCityRoom::Setup();
    setShortDescription("A braced passage leads up toward the old "
        "foundations of the Aegis Guard hall.");
    addExit("south", "/areas/eledhel/under-city/trunk/11x0.c");
    addExit("up", "/areas/eledhel/central-city/aegis-hall/0x0.c");
}

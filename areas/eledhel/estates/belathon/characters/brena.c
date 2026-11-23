//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Brena");
    short("Lady Brena Belathon");
    description("The polished matron of House Belathon watches every "
        "visitor with a careful, measuring smile.");
    Gender("female");
    Race("maegenstryd");
    SetUpPersonaOfLevel("swordsman", 6);
}

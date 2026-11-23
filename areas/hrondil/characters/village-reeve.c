//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Gwineth");
    short("Gwineth, the village reeve");
    description("Gwineth settles disputes among the upland farms and "
        "keeps the village stores accounted for.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("swordsman", 3);
}

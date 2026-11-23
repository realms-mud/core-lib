//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Arawn");
    short("Lord Arawn of House Belectar");
    description("Arawn oversees the barley fields and the contracts that "
        "supply the nearby coast.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("swordsman", 6);
}

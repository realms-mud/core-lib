//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Aeryn");
    short("Aeryn, a young child of House Kirin");
    description("Aeryn plays in the manor's sunny rooms, watched closely "
        "by her family.");
    Gender("female");
    Race("maegenstryd");
    SetUpPersonaOfLevel("swordsman", 1);
}

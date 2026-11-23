//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Aelwen");
    short("Aelwen, keeper of the market gardens");
    description("Aelwen rotates the crops and records which city stalls "
        "need the early harvest.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("farmer", 2);
}

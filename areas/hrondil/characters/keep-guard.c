//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Hrondil keep guard");
    short("a Hrondil keep guard");
    description("A household guard watches the keep's entrance.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("swordsman", 4);
}

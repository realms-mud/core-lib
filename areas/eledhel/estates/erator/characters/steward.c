//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Elenwen");
    short("Elenwen, steward of House Erator");
    description("Elenwen keeps the household accounts and the field "
        "workers' schedules.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("farmer", 3);
}

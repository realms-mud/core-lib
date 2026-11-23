//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Aerandir");
    short("Lord Aerandir of House Anduradan");
    description("Aerandir oversees the grain tenants and the ditches "
        "that keep the lower fields drained.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("swordsman", 5);
}

//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Eirion");
    short("Eirion, steward of House Anduradan");
    description("Eirion keeps the harvest tallies and arranges carts "
        "for the northern road.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("farmer", 2);
}

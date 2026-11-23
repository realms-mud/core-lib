//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Belen");
    short("Belen, a market porter");
    description("Belen carries a folded sack and waits for the "
        "next shop to call for a delivery.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("farmer", 4);
    addConversation(
        "/areas/eledhel/central-city/characters/"
        "market-porterConversation.c");
}

//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Gorwen");
    short("Gorwen, a hammer-smith and tool maker");
    description("Gorwen makes and repairs sturdy tools for the "
        "storehouses, builders, and tradespeople of the ward.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("blacksmith", 6);
    addConversation(
        "/areas/eledhel/central-city/characters/"
        "old-city-hammer-smithConversation.c");
}

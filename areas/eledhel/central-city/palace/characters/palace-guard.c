//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Palace guard");
    short("a palace guard");
    description("The guard stands watch over the household passage and "
        "keeps a clear view of the rooms beyond.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("city guard", 6);
    addConversation(
        "/areas/eledhel/central-city/palace/characters/palace-guardConversation.c");
}

//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Tiriel");
    short("Tiriel, the palace chamberlain");
    description("Tiriel tracks the household's appointments, stores, and "
        "requests for the king's attention.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("grocer", 5);
    addConversation(
        "/areas/eledhel/central-city/palace/characters/chamberlainConversation.c");
}

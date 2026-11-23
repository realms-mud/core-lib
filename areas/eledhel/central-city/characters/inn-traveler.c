//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Ryneth");
    short("Ryneth, a traveler at the neighborhood inn");
    description("Ryneth carries a small pack and asks passersby "
        "about the inn's common room.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("farmer", 3);
    addConversation(
        "/areas/eledhel/central-city/characters/"
        "inn-travelerConversation.c");
}

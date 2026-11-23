//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Nethor");
    short("Nethor, a records copyist");
    description("Nethor carries a packet of copied pages toward "
        "the civic offices near the plaza.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("farmer", 3);
    addConversation(
        "/areas/eledhel/central-city/characters/"
        "records-copyistConversation.c");
}

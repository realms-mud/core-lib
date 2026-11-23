//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Goven");
    short("Goven, a guest of the Golden Flask");
    description("Goven pauses outside the Golden Flask after "
        "leaving a travel pack in his room.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("farmer", 3);
    addConversation(
        "/areas/eledhel/central-city/characters/"
        "inn-guestConversation.c");
}

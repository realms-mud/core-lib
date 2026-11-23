//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Sira");
    short("Sira, a market porter resting after work");
    description("Sira has set down an empty handcart and is taking "
        "a short break before the evening deliveries.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("grocer", 3);
    addConversation(
        "/areas/eledhel/central-city/characters/tavern-guestConversation.c");
}

//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Vardan");
    short("Vardan, a visitor to the Werric temple");
    description("Vardan pauses on the temple street with a small "
        "bundle of books for the outpost.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("farmer", 3);
    addConversation(
        "/areas/eledhel/central-city/characters/"
        "werric-visitorConversation.c");
}

//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Estel");
    short("Estel, a visitor to the Werric outpost");
    description("Estel waits outside the temple doors with a "
        "question for one of the knights.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("farmer", 3);
    addConversation(
        "/areas/eledhel/central-city/characters/"
        "temple-visitorConversation.c");
}

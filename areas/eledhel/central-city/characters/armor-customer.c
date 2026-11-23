//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Nereth");
    short("Nereth, a watch orderly with a damaged gorget");
    description("Nereth has brought a guard's gorget in for inspection "
        "rather than risk sending it back into service as it is.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("farmer", 3);
    addConversation(
        "/areas/eledhel/central-city/characters/"
        "armor-customerConversation.c");
}

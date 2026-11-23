//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Thalion");
    short("Thalion, a cartwright");
    description("Thalion measures the space between the cart wheels "
        "and the edge of the east lane.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("farmer", 4);
    addConversation(
        "/areas/eledhel/central-city/characters/"
        "cartwrightConversation.c");
}

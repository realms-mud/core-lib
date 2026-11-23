//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Korin");
    short("Korin, a kitchen worker collecting provisions");
    description("Korin compares a short list of vegetables with "
        "the brewery's produce on the counter.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("grocer", 2);
    addConversation(
        "/areas/eledhel/central-city/characters/brewery-customerConversation.c");
}

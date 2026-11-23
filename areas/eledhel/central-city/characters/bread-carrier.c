//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Selwen");
    short("Selwen, a bakery's bread carrier");
    description("Selwen carries covered baskets of bread to small "
        "shops before the street grows crowded.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("grocer", 2);
    addConversation(
        "/areas/eledhel/central-city/characters/"
        "bread-carrierConversation.c");
}

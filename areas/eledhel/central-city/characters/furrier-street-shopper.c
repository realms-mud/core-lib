//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Faren");
    short("Faren, a shopper outside the furrier");
    description("Faren compares the weather with the furrier's "
        "display before deciding whether to buy a warmer cloak.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("farmer", 2);
    addConversation(
        "/areas/eledhel/central-city/characters/"
        "furrier-street-shopperConversation.c");
}

//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Celya");
    short("Celya, a market customer with a woven basket");
    description("Celya compares her shopping list with the produce "
        "in her basket before heading back to her household.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("farmer", 2);
    addConversation(
        "/areas/eledhel/southern-city/characters/"
        "market-customerConversation.c");
}

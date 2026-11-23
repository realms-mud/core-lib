//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Aven");
    short("Aven, the royal legal adviser");
    description("Aven keeps the crown's legal precedents close at hand and "
        "reviews petitions before they reach the council table.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("grocer", 5);
    addConversation(
        "/areas/eledhel/central-city/palace/characters/court-advisorConversation.c");
}

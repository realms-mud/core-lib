//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Averin");
    short("Averin, a clerk of the Halls of Justice");
    description("Averin records petitions in a careful hand and keeps "
        "the court's files in strict order.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("priest", 5);
    addConversation(
        "/areas/eledhel/southern-city/halls-of-justice/characters/"
        "judge-clerkConversation.c");
}

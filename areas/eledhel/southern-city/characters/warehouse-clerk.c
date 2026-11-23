//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Tavrin");
    short("Tavrin, a warehouse tally clerk");
    description("Tavrin records each crate that enters the warehouse "
        "and checks its mark before it is moved to storage.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("grocer", 5);
    addConversation(
        "/areas/eledhel/southern-city/characters/"
        "warehouse-clerkConversation.c");
}

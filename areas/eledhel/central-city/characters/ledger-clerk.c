//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Wethen");
    short("Wethen, a junior ledger clerk");
    description("Wethen walks between the avenue and a counting room "
        "with a slate tucked under one arm.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("farmer", 2);
    addConversation(
        "/areas/eledhel/central-city/characters/"
        "ledger-clerkConversation.c");
}

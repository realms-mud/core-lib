//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Court scribe");
    short("a court scribe");
    description("The scribe keeps petitions, household orders, and council "
        "minutes in separate, carefully labelled stacks.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("grocer", 4);
    addConversation(
        "/areas/eledhel/central-city/palace/characters/court-scribeConversation.c");
}

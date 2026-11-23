//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Olyne");
    short("Olyne, a clerk waiting for a fitting");
    description("Olyne waits by the fitting counter with a folded "
        "length of cloth and a note from her employer.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("grocer", 3);
    addConversation(
        "/areas/eledhel/central-city/characters/tailor-customerConversation.c");
}

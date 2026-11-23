//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Selyra");
    short("Selyra, tailor of the royal ward");
    description("Selyra measures cloth carefully and keeps the "
        "tailor's shelves in order for the Old City's residents.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("grocer", 5);
    addConversation(
        "/areas/eledhel/central-city/characters/tailorConversation.c");
}

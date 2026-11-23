//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Eledhel crier");
    short("the city crier");
    description("The crier checks the public notice board and repeats "
        "announcements for people crossing the plaza.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("grocer", 4);
    addConversation(
        "/areas/eledhel/central-city/characters/city-crierConversation.c");
}

//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Aegis cadet");
    short("an Aegis cadet at practice");
    description("The cadet repeats a measured drill, pausing to correct "
        "each stance before starting again.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("city guard", 4);
    addConversation(
        "/areas/eledhel/central-city/characters/aegis-cadetConversation.c");
}

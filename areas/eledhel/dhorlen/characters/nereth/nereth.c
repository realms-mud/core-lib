//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Nereth");
    short("Nereth, miller of Dhorlen");
    description("Nereth keeps one hand near the grain measure and "
        "the other clear of the turning stones.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("miller", 4);
    addConversation("/areas/eledhel/dhorlen/characters/nereth/"
        "startingConversation.c");
}

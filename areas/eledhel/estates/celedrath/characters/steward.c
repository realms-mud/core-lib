//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Rilion");
    short("Rilion, steward of the Celedrath household");
    description("Rilion manages the estate's coastal fields and "
        "keeps its accounts for the household.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("farmer", 3);
    addConversation(
        "/areas/eledhel/estates/celedrath/characters/stewardConversation.c");
}

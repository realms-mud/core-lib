//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Rovin");
    short("Rovin, a traveler choosing a new belt");
    description("Rovin compares a worn belt with the leather goods "
        "on Tavren's shelves before continuing his journey.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("grocer", 3);
    addConversation(
        "/areas/eledhel/central-city/characters/leather-shopperConversation.c");
}

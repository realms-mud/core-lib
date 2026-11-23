//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Calven");
    short("Calven, a brewer on the Old City avenue");
    description("Calven makes small batches of apple cider and "
        "keeps common provisions for the neighborhood.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("grocer", 5);
    addConversation(
        "/areas/eledhel/central-city/characters/brewerConversation.c");
}

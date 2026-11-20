//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Edrin");
    short("Edrin, keeper of the Drovers' Rest");
    description("Edrin keeps a ledger of flock counts, cart repairs, and "
        "the road conditions south to Linwaeth.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("innkeeper", 5);
    addConversation(
        "/areas/eledhel/southwest-rural-four/characters/"
        "innkeeperConversation.c");
}

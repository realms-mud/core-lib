//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Hareth");
    short("Hareth, keeper of the royal stables");
    description("Hareth checks each horse's tack and feed before the day's "
        "riders leave the palace grounds.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("innkeeper", 5);
    addConversation(
        "/areas/eledhel/central-city/palace/characters/stablemasterConversation.c");
}

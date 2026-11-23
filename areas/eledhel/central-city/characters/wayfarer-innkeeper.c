//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Teren");
    short("Teren, keeper of the Wayfarer Inn");
    description("Teren runs a modest house for travelers and "
        "tradespeople who need a meal and a quiet bed.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("innkeeper", 6);
    addConversation(
        "/areas/eledhel/central-city/characters/"
        "wayfarer-innkeeperConversation.c");
}

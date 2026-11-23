//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Maerin");
    short("Maerin, keeper of the southern inn");
    description("Maerin keeps the common room orderly and makes "
        "sure travelers know where to find a meal and a bed.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("innkeeper", 6);
    addConversation(
        "/areas/eledhel/southern-city/characters/"
        "innkeeperConversation.c");
}

//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Dalen");
    short("Dalen, keeper of the Gate Street tavern");
    description("Dalen keeps a plain, welcoming tavern for teamsters, "
        "market porters, and the residents of the Old City.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("innkeeper", 6);
    addConversation(
        "/areas/eledhel/central-city/characters/tavernkeeperConversation.c");
}

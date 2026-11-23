//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Vesra");
    short("Vesra, a traveling singer");
    description("Vesra warms her voice before a neighborhood "
        "performance and keeps a small book of old road songs.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("grocer", 3);
    addConversation(
        "/areas/eledhel/central-city/characters/theater-performerConversation.c");
}

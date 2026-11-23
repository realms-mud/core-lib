//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Elmor");
    short("Elmor, a theater handbill runner");
    description("Elmor carries a neat stack of theater notices "
        "between the playhouse and the neighboring streets.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("grocer", 2);
    addConversation(
        "/areas/eledhel/central-city/characters/"
        "theater-handbill-runnerConversation.c");
}

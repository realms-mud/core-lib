//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Thessan");
    short("Thessan, the jeweler");
    description("Thessan wears a jeweler's loupe on a cord and a "
        "measuring caliper in his pocket. His workbench is spotless, "
        "with every tool returned to its marked place.");

    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("grocer", 5);

    addConversation(
        "/areas/eledhel/southern-city/characters/thessan/startingConversation.c");
}

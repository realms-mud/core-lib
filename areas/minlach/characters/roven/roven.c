//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Roven");
    short("Roven, the innkeeper");
    description("Roven is broad-shouldered and quick to smile. He keeps "
        "the common room warm, the lamps trimmed, and a quiet eye on the "
        "travelers coming in from the coast road.");

    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("innkeeper", 5);

    addConversation(
        "/areas/minlach/characters/roven/startingConversation.c");
    registerEvent(load_object("/areas/minlach/quests/resident-events.c"));
}

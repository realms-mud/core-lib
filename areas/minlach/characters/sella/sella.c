//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Sella");
    short("Sella, a market seller");
    description("Sella keeps a tidy stall of dried fish, apples, onions, "
        "and travel bread. She knows which ships have arrived and which "
        "road crews are due back.");

    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("grocer", 4);

    addConversation(
        "/areas/minlach/characters/sella/startingConversation.c");
    registerEvent(load_object("/areas/minlach/quests/resident-events.c"));
}

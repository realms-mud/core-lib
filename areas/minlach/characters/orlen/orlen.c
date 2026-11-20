//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Orlen");
    short("Orlen, the town scribe");
    description("Orlen wears wool sleeves protected by narrow leather "
        "cuffs. His spectacles sit low on his nose, and he weighs his "
        "words as carefully as the papers on his desk.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("grocer", 3);
    addConversation("/areas/minlach/characters/orlen/startingConversation.c");
    registerEvent(load_object("/areas/minlach/quests/resident-events.c"));
}

//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Neris");
    short("Neris, a harbor pilot");
    description("Neris wears a salt-stiff coat and keeps a small "
        "signal book tucked inside its breast. She studies the water "
        "while she speaks, rarely standing with her back to the bay.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("grocer", 5);
    addConversation("/areas/minlach/characters/neris/startingConversation.c");
    registerEvent(load_object("/areas/minlach/quests/resident-events.c"));
}

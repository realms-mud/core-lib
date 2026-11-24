//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Basil");
    short("Basil, an Aegis road surveyor");
    description("Basil keeps a folded route map beneath one arm and "
        "a weather-stained report case at his belt. His Aegis badge "
        "is visible, though his attention is on the survey board and "
        "the local watch rather than on giving orders.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("city guard", 9);
    addConversation("/areas/minlach/characters/basil/startingConversation.c");
    registerEvent(load_object("/areas/minlach/quests/resident-events.c"));
}

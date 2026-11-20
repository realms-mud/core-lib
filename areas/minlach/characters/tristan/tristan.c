//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Tristan Caranil");
    short("Tristan Caranil, the constable");
    description("The constable wears a weathered cloak over a neat "
        "uniform and watches the street with an experienced, steady gaze. "
        "A notebook and a plain sword hang at his belt.");

    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("city guard", 8);

    addConversation(
        "/areas/minlach/characters/tristan/startingConversation.c");
    registerEvent(load_object("/areas/minlach/quests/resident-events.c"));
}

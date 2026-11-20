//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Fennel");
    short("Fennel, a harbor factor");
    description("Fennel wears a heavy wool coat and carries a slate "
        "covered in cargo marks. His attention is fixed on the quay, "
        "where every crate must be counted before it leaves the harbor.");

    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("grocer", 5);

    addConversation(
        "/areas/minlach/characters/fennel/startingConversation.c");
    registerEvent(load_object("/areas/minlach/quests/resident-events.c"));
}

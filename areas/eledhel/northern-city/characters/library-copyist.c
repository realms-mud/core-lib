//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Saelis");
    short("Saelis, a library copyist");
    description("Saelis carefully copies entries from the histories and "
        "genealogy shelves, pausing to mend worn bindings between visitors.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("grocer", 4);
    addConversation(
        "/areas/eledhel/northern-city/characters/library-copyistConversation.c");
}

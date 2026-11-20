//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Durma");
    short("Durma, the armorer");
    description("Durma is compact and strong, with soot along one cheek "
        "and a leather apron scarred by years at the forge. She checks "
        "every rivet before a piece leaves her bench.");

    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("blacksmith", 6);

    addConversation(
        "/areas/eledhel/southern-city/characters/durma/startingConversation.c");
}

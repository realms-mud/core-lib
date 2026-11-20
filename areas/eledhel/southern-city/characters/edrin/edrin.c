//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Edrin");
    short("Edrin, the bookseller");
    description("Edrin keeps the shelves orderly and the prices fair. "
        "His ink-stained fingers and careful manner suggest that he "
        "would rather read a ledger than haggle over it.");

    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("grocer", 4);

    addConversation(
        "/areas/eledhel/southern-city/characters/edrin/startingConversation.c");
}

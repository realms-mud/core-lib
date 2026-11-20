//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Vethra");
    short("Vethra, the arcane goods dealer");
    description("Vethra is composed and precise, with dark hair tied "
        "back from a work apron. Small, carefully labeled jars line "
        "the shelves behind her.");

    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("priest", 6);

    addConversation(
        "/areas/eledhel/southern-city/characters/vethra/startingConversation.c");
}

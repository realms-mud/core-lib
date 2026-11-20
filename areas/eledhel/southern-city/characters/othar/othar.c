//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Othar");
    short("Othar, the bowyer");
    description("Othar tests each bow against a marked draw line. "
        "Shavings curl around the workbench, and a row of finished "
        "staves rests well away from the hearth.");

    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("blacksmith", 6);

    addConversation(
        "/areas/eledhel/southern-city/characters/othar/startingConversation.c");
}

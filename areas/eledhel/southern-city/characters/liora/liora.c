//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Liora");
    short("Liora, the light armorer");
    description("Liora keeps lighter armor and travel leathers on "
        "separate racks, sorted by size. She measures carefully and "
        "expects customers to move before she approves a fitting.");

    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("blacksmith", 5);

    addConversation(
        "/areas/eledhel/southern-city/characters/liora/startingConversation.c");
}

//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Morwen");
    short("Princess Morwen of Eledhel");
    description("Princess Morwen's presence is graceful, her "
        "expression alert and touched with playful impatience.");
    Gender("female");
    Race("maegenstryd");
    SetUpPersonaOfLevel("city guard", 12);
    addConversation(
        "/areas/eledhel/central-city/palace/characters/"
        "morwenConversation.c");
}

//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Nethwen");
    short("Nethwen, a tailor of the south ward");
    description("Nethwen makes durable everyday clothes and takes "
        "alterations for workers who cannot afford to replace a garment.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("grocer", 5);
    addConversation(
        "/areas/eledhel/central-city/characters/"
        "old-city-tailor-twoConversation.c");
}

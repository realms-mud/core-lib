//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Barad");
    short("Barad, an armorer of the old ward");
    description("Barad fits practical armor for city guards and "
        "travelers, and keeps damaged pieces out of the sales racks.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("blacksmith", 7);
    addConversation(
        "/areas/eledhel/central-city/characters/"
        "old-city-armorerConversation.c");
}

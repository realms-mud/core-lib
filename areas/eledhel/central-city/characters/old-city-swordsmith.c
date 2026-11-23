//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Tirwen");
    short("Tirwen, swordsmith of the royal ward");
    description("Tirwen keeps a careful line of serviceable swords and "
        "works through a steady queue of repairs and commissions.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("blacksmith", 7);
    addConversation(
        "/areas/eledhel/central-city/characters/"
        "old-city-swordsmithConversation.c");
}

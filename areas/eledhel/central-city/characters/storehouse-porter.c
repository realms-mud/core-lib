//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Sarneth");
    short("Sarneth, a storehouse porter");
    description("Sarneth carries a tally stick and waits for a "
        "cartload to be called forward.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("farmer", 4);
    addConversation(
        "/areas/eledhel/central-city/characters/"
        "storehouse-porterConversation.c");
}

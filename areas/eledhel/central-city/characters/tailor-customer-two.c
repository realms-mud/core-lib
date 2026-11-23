//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Rillan");
    short("Rillan, a clerk waiting on a mended coat");
    description("Rillan holds a patched coat over one arm and waits "
        "for Nethwen to finish an alteration.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("farmer", 2);
    addConversation(
        "/areas/eledhel/central-city/characters/"
        "tailor-customer-twoConversation.c");
}

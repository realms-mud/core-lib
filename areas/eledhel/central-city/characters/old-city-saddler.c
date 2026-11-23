//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Myrwen");
    short("Myrwen, a saddler and harness maker");
    description("Myrwen repairs working tack for couriers, carters, and "
        "the households that keep horses in the old ward.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("grocer", 5);
    addConversation(
        "/areas/eledhel/central-city/characters/"
        "old-city-saddlerConversation.c");
}

//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Saran");
    short("Saran, a carter waiting on a repaired harness");
    description("Saran has left a work harness with Myrwen and is "
        "counting the cost of keeping a loaded cart idle.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("farmer", 3);
    addConversation(
        "/areas/eledhel/central-city/characters/"
        "saddlery-customerConversation.c");
}

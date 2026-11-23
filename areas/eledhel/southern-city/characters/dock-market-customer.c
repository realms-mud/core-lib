//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Pethren");
    short("Pethren, a sailor buying provisions");
    description("Pethren waits at the provisions counter with "
        "a small list for the next harbor watch.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("grocer", 3);
    addConversation(
        "/areas/eledhel/southern-city/characters/dock-market-customerConversation.c");
}

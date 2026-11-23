//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Raeth");
    short("Raeth, a messenger outside the Aegis hall");
    description("Raeth waits outside the Aegis hall with a sealed "
        "dispatch for its officers.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("farmer", 3);
    addConversation(
        "/areas/eledhel/central-city/characters/"
        "aegis-messengerConversation.c");
}

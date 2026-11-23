//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Alwen");
    short("Alwen, a flower seller");
    description("Alwen carries small bunches of hardy flowers toward "
        "the busier squares of the old city.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("grocer", 3);
    addConversation(
        "/areas/eledhel/central-city/characters/"
        "flower-sellerConversation.c");
}

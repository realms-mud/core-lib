//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Keldan");
    short("Keldan, a supplier outside the inn");
    description("Keldan waits with a small delivery for the inn "
        "at the end of the east lane.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("grocer", 4);
    addConversation(
        "/areas/eledhel/central-city/characters/"
        "inn-supplierConversation.c");
}

//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Lethwyn");
    short("Lethwyn, manager of the neighborhood theater");
    description("Lethwyn keeps the small theater running and "
        "arranges local music and short plays.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("grocer", 4);
    addConversation(
        "/areas/eledhel/central-city/characters/theater-managerConversation.c");
}

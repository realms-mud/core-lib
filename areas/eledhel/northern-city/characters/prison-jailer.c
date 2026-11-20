//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Oreth");
    short("Oreth, a prison jailer");
    description("Oreth minds the cell passage and keeps the records room "
        "locked when the prison is in use.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("city guard", 8);
    addConversation(
        "/areas/eledhel/northern-city/characters/prison-jailerConversation.c");
}

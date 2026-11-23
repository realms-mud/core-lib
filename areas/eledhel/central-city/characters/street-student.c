//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Edran");
    short("Edran, a student returning from the academy");
    description("Edran carries a slate and a stack of lessons "
        "along the eastbound street.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("farmer", 2);
    addConversation(
        "/areas/eledhel/central-city/characters/"
        "street-studentConversation.c");
}

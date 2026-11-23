//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Ardenel");
    short("King Ardenel of Eledhel");
    description("King Ardenel is aged and careworn, but greets "
        "visitors with a warmth that softens his formal bearing.");
    Gender("male");
    Race("maegenstryd");
    SetUpPersonaOfLevel("city guard", 20);
    addConversation(
        "/areas/eledhel/central-city/palace/characters/"
        "ardenelConversation.c");
}

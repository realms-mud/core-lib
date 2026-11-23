//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Bereth");
    short("Bereth, master of the southern foundry");
    description("Bereth directs the foundry's crews and keeps the "
        "finished work separate from untested castings.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("blacksmith", 8);
    addConversation(
        "/areas/eledhel/southern-city/characters/"
        "foundry-masterConversation.c");
}

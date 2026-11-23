//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Orvan");
    short("Orvan, a smelter worker");
    description("Orvan watches the furnace and tests each new bar "
        "of metal before it is sent to the smiths.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("blacksmith", 6);
    addConversation(
        "/areas/eledhel/southern-city/characters/"
        "smelterConversation.c");
}

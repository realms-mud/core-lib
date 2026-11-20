//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Aderyn");
    short("Aderyn, an Anor fisher");
    description("Aderyn sorts the catch and watches the water for "
        "boats delayed by the weather.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("fisher", 4);
    addConversation("/areas/anor/characters/fisherConversation.c");
}

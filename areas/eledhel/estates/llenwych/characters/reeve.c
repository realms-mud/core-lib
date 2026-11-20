//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Meren");
    short("Meren, reeve of House Llenwych");
    description("Meren oversees the sheep flocks and wool accounts "
        "for the Llenwych household.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("farmer", 3);
    addConversation(
        "/areas/eledhel/estates/llenwych/characters/reeveConversation.c");
}

//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Tavren");
    short("Tavren, reeve of House Oeldhen");
    description("Tavren keeps the field accounts and arranges the "
        "estate's deliveries to Eledhel.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("farmer", 3);
    addConversation(
        "/areas/eledhel/estates/oeldhen/characters/reeveConversation.c");
}

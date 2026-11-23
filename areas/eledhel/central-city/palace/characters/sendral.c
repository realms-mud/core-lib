//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Sendral");
    short("Sendral, castellan of Eledhel");
    description("The old castellan is courteous and unhurried. He keeps "
        "the palace gate, household, and its older passages in careful order.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("city guard", 8);
    addConversation(
        "/areas/eledhel/central-city/palace/characters/sendralConversation.c");
    registerEvent(load_object(
        "/areas/eledhel/central-city/palace/characters/sendralEvents.c"));
}

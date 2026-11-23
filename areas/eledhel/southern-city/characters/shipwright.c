//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Edril");
    short("Edril, master shipwright");
    description("Edril inspects the yard's frames and fittings "
        "before approving any repair for the harbor fleet.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("blacksmith", 8);
    addConversation(
        "/areas/eledhel/southern-city/characters/shipwrightConversation.c");
}

//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Othwen");
    short("Othwen, a shipwright's apprentice");
    description("Othwen sorts sailcloth and coils of rigging "
        "under the shipwright's careful supervision.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("blacksmith", 3);
    addConversation(
        "/areas/eledhel/southern-city/characters/shipyard-apprenticeConversation.c");
}

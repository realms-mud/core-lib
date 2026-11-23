//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Meleth");
    short("Meleth, a provisioner on the southern trade street");
    description("Meleth stocks the ordinary goods that keep a "
        "household or a short journey supplied.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("grocer", 5);
    addConversation(
        "/areas/eledhel/central-city/characters/"
        "old-city-provisionerConversation.c");
}

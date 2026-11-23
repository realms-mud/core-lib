//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Nareth");
    short("Nareth, a foreman on the southern quay");
    description("Nareth checks the quay's cargo tallies and keeps "
        "the dockhands clear of the working lines.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("grocer", 5);
    addConversation(
        "/areas/eledhel/southern-city/characters/dock-foremanConversation.c");
}

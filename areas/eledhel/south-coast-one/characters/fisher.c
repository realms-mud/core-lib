//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Mairen");
    short("Mairen, a fisher of the southern hamlet");
    description("Mairen mends a net while keeping one eye on the tide "
        "and the road that brings salt and flour to the hamlet.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("fisher", 3);
    addConversation(
        "/areas/eledhel/south-coast-one/characters/fisherConversation.c");
}

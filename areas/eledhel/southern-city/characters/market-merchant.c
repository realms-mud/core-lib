//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Marden");
    short("Marden, a provisions seller at the southern market");
    description("Marden sorts produce and travel food with the care "
        "of someone who knows how quickly a bad measure spoils a journey.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("grocer", 5);
    addConversation(
        "/areas/eledhel/southern-city/characters/"
        "market-merchantConversation.c");
}

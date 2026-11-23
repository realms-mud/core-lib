//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Calen");
    short("Calen, a ward guard");
    description("Calen watches the eastbound lane and lets the "
        "pedestrians pass without obstructing the road.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("farmer", 4);
    addConversation(
        "/areas/eledhel/central-city/characters/"
        "ward-guardConversation.c");
}

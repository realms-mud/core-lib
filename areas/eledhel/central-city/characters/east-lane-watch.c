//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Siven");
    short("Siven, a watchman on the east lane");
    description("Siven keeps the east lane clear where the houses "
        "and work yards face the road.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("farmer", 4);
    addConversation(
        "/areas/eledhel/central-city/characters/"
        "east-lane-watchConversation.c");
}

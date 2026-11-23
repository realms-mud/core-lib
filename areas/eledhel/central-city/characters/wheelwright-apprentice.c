//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Rovan");
    short("Rovan, a wheelwright's apprentice");
    description("Rovan carries a spoke gauge and studies every cart "
        "that passes along the avenue.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("farmer", 2);
    addConversation(
        "/areas/eledhel/central-city/characters/"
        "wheelwright-apprenticeConversation.c");
}

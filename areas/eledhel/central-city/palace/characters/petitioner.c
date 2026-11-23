//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Petitioner");
    short("a petitioner waiting for court");
    description("The petitioner holds a folded request and waits quietly "
        "for an audience with the royal household.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("grocer", 3);
    addConversation(
        "/areas/eledhel/central-city/palace/characters/petitionerConversation.c");
}

//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Sergeant Talan");
    short("Sergeant Talan of the Phaedra");
    description("Talan keeps the command chamber in order and answers "
        "questions about the headquarters without discussing active orders.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("city guard", 11);
    addConversation(
        "/areas/eledhel/northern-city/characters/phaedra-sergeantConversation.c");
}

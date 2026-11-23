//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Perrin");
    short("Perrin, a traveler resting at the inn");
    description("Perrin sits over a bowl of food, resting before "
        "continuing along the southern road.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("farmer", 3);
    addConversation(
        "/areas/eledhel/southern-city/characters/"
        "inn-guestConversation.c");
}

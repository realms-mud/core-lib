//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Lethen");
    short("Lethen, a traveler resting at the Wayfarer");
    description("Lethen rests by the common-room hearth after bringing "
        "a small load into the city.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("farmer", 3);
    addConversation(
        "/areas/eledhel/central-city/characters/"
        "wayfarer-guestConversation.c");
}

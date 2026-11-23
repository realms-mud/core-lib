//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Gwineth");
    short("Gwineth, an apprentice from the Aegis academy");
    description("Gwineth walks between the academy and the guard hall "
        "with a bundle of practice notes.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("farmer", 2);
    addConversation(
        "/areas/eledhel/central-city/characters/"
        "academy-apprenticeConversation.c");
}

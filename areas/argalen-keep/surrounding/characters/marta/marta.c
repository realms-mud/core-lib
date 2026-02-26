//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("marta");
    short("Marta the grocer");
    description("Marta is a wiry, sharp-eyed woman of advancing years "
        "with silver-streaked hair pulled back in a practical bun. "
        "Her hands are quick and precise as they sort through her "
        "wares, and she has the air of someone who has never been "
        "cheated twice on the same deal.");

    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("grocer", 5);

    addConversation(
        "/areas/argalen-keep/surrounding/characters/marta/startingConversation.c");
}

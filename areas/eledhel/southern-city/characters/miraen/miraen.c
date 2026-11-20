//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Miraen");
    short("Miraen, the gem crafter");
    description("Miraen leans over a padded bench where several "
        "half-finished settings are arranged in shallow trays. She "
        "speaks little while she works, but misses no detail.");

    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("grocer", 5);

    addConversation(
        "/areas/eledhel/southern-city/characters/miraen/startingConversation.c");
}

//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Morleth");
    short("Morleth, the wiry old herbalist");
    description("Morleth weighs remedies with practiced care and keeps "
        "several books of history and plant lore close at hand.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("grocer", 6);
    addConversation(
        "/areas/eledhel/northern-city/characters/morlethConversation.c");
}

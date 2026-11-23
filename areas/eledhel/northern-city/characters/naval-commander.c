//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Narev");
    short("Narev, commander of the harbor watch");
    description("Narev studies the harbor approaches and checks the day's "
        "berth and patrol notes before giving orders.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("city guard", 10);
    addConversation(
        "/areas/eledhel/northern-city/characters/naval-commanderConversation.c");
}

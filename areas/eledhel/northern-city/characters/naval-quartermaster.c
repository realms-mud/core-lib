//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Calven");
    short("Calven, the naval quartermaster");
    description("Calven keeps the pier's stores counted and records each "
        "crate issued to a ship or watch crew.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("grocer", 5);
    addConversation(
        "/areas/eledhel/northern-city/characters/naval-quartermasterConversation.c");
}

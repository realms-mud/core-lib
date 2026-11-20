//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Nerith");
    short("Nerith, the herbalist");
    description("Nerith's shop smells of dried mint, pine resin, and "
        "warm earth. She sorts the gathered plants into labeled "
        "bundles and keeps a small notebook of where each grows.");

    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("priest", 5);

    addConversation(
        "/areas/eledhel/southern-city/characters/nerith/startingConversation.c");
}

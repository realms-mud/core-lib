//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Selen");
    short("Selen, a naval watch officer");
    description("Selen watches the northern pier and records the ships "
        "entering or leaving the harbor.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("city guard", 7);
    addConversation(
        "/areas/eledhel/northern-city/characters/naval-watchConversation.c");
}

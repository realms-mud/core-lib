//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Tavren");
    short("Tavren, leatherworker of the royal ward");
    description("Tavren cuts and repairs sturdy leather goods for "
        "households, riders, and travelers crossing the capital.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("blacksmith", 6);
    addConversation(
        "/areas/eledhel/central-city/characters/leatherworkerConversation.c");
}

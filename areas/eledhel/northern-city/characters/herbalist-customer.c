//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Tirren");
    short("Tirren, a sailor seeking a salve");
    description("Tirren waits while Morleth prepares a salve for the "
        "irritated hands he has earned hauling lines at the docks.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("grocer", 3);
    addConversation(
        "/areas/eledhel/northern-city/characters/herbalist-customerConversation.c");
}

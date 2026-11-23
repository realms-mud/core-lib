//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Iveren");
    short("Iveren, the northern dockmaster");
    description("Iveren checks mooring lines and assigns the guarded berths "
        "beneath the naval headquarters.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("grocer", 5);
    addConversation(
        "/areas/eledhel/northern-city/characters/north-dockmasterConversation.c");
}

//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Nerion");
    short("Nerion, a sailor buying provisions");
    description("Nerion checks the stall's supplies while waiting for his "
        "ship's next watch to assemble.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("fisher", 3);
    addConversation(
        "/areas/eledhel/northern-city/characters/north-dock-customerConversation.c");
}

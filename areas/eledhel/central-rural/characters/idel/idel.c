//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Idel");
    short("Idel, keeper of the common pasture");
    description("Idel's boots are muddy at the seams and a bundle "
        "of repaired rope hangs from her belt. She checks the barn "
        "latches while listening for the animals beyond the yard.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("farmer", 3);
    addConversation("/areas/eledhel/central-rural/characters/"
        "idel/startingConversation.c");
}

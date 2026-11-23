//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Aelion");
    short("Aelion, a mason choosing a replacement hammer");
    description("Aelion's old hammer has loosened at the head, and "
        "he has stopped work until he can replace or repair it.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("farmer", 3);
    addConversation(
        "/areas/eledhel/central-city/characters/"
        "hammer-customerConversation.c");
}

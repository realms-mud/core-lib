//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Harn");
    short("Harn, the swordsmith");
    description("Harn stands beside the forge with a heavy hammer "
        "balanced in one hand. He studies the edge of every blade "
        "against the light before setting it on the rack.");

    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("blacksmith", 7);

    addConversation(
        "/areas/eledhel/southern-city/characters/harn/startingConversation.c");
}

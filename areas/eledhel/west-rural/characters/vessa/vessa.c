//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Vessa");
    short("Vessa, keeper of the bee yard");
    description("Vessa wears a smoke-stained veil rolled above "
        "her brow. She keeps the living skeps well apart from the "
        "empty stands and has tied a strip of blue cloth around "
        "each hive that still hums.");

    Gender("female");
    Race("human");

    addConversation(
        "/areas/eledhel/west-rural/characters/vessa/startingConversation.c");
}

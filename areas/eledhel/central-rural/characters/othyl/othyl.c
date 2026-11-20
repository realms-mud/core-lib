//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Othyl");
    short("Othyl, the yard hand");
    description("Othyl keeps the wayhouse yard in order. A coil "
        "of leather thong hangs from her belt, and she listens "
        "to each cart as it crosses the stones before deciding "
        "whether its wheel needs attention.");

    Gender("female");
    Race("human");

    addConversation(
        "/areas/eledhel/central-rural/characters/othyl/startingConversation.c");
}

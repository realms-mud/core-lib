//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Lirwen");
    short("Lirwen, a rope-mender on the quay");
    description("Lirwen sits beside a coil of line, repairing "
        "frayed sections before the next tide turns.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("grocer", 4);
    addConversation(
        "/areas/eledhel/southern-city/characters/rope-menderConversation.c");
}

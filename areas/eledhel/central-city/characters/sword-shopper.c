//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Elen");
    short("Elen, a shopper outside the swordsmith");
    description("Elen has come to the smith for a practical blade "
        "and is considering the cost before entering.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("farmer", 3);
    addConversation(
        "/areas/eledhel/central-city/characters/"
        "sword-shopperConversation.c");
}

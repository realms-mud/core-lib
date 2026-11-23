//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Hithen");
    short("Hithen, a courier waiting on a repaired coat");
    description("Hithen waits outside the tailor with a travel "
        "satchel over one shoulder.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("farmer", 3);
    addConversation(
        "/areas/eledhel/central-city/characters/"
        "tailor-courierConversation.c");
}

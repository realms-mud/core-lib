//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Rianor");
    short("Rianor, a supplier of leather scraps");
    description("Rianor carries a bundle of prepared leather "
        "toward the shops on the southern street.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("grocer", 4);
    addConversation(
        "/areas/eledhel/central-city/characters/"
        "leather-supplierConversation.c");
}

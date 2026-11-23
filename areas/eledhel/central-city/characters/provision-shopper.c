//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Norwen");
    short("Norwen, a shopper near the provisioner");
    description("Norwen carries a small household list and checks "
        "the shops along the trade street.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("grocer", 3);
    addConversation(
        "/areas/eledhel/central-city/characters/"
        "provision-shopperConversation.c");
}

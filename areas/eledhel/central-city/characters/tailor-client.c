//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Melwen");
    short("Melwen, a tailor's client");
    description("Melwen waits outside the tailor's shop with a "
        "folded length of cloth for an alteration.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("farmer", 2);
    addConversation(
        "/areas/eledhel/central-city/characters/"
        "tailor-clientConversation.c");
}

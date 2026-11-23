//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Orwen");
    short("Orwen, a cook buying supplies for a household");
    description("Orwen compares the list in his hand with the goods "
        "on Meleth's shelves before returning to his kitchen.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("farmer", 3);
    addConversation(
        "/areas/eledhel/central-city/characters/"
        "provisioner-customerConversation.c");
}

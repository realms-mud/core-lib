//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Deren");
    short("Deren, a porter at the west approach");
    description("Deren helps unload small carts before they join the "
        "busier streets inside the city.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("farmer", 3);
    addConversation(
        "/areas/eledhel/central-city/characters/"
        "west-approach-porterConversation.c");
}

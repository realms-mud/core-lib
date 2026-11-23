//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Ivran");
    short("Ivran, a street musician");
    description("Ivran rests a small drum against his knee and "
        "watches the flow of people along the avenue.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("farmer", 3);
    addConversation(
        "/areas/eledhel/central-city/characters/"
        "street-musicianConversation.c");
}

//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Haeren");
    short("Haeren, a watch patrol on the west avenue");
    description("Haeren keeps an eye on carts and pedestrians as "
        "they approach the civic quarter.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("farmer", 4);
    addConversation(
        "/areas/eledhel/central-city/characters/"
        "avenue-watchConversation.c");
}

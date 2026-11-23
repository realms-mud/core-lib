//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Irielle");
    short("Irielle, a street lamplighter");
    description("Irielle's ash-blond hair is pinned under a kerchief, "
        "and gray eyes check every lamp. She is rational and diligent.");
    Gender("female");
    Race("maegenstryd");
    SetUpPersonaOfLevel("city guard", 4);
    addTrait("/lib/instances/traits/eyes/gray.c");
    addTrait("/lib/instances/traits/hair/ash-blond.c");
    addTrait("/lib/instances/traits/personality/rational.c");
    addTrait("/lib/instances/traits/personality/diligent.c");
    addConversation(
        "/areas/eledhel/southern-city/characters/streets/"
        "irielleConversation.c");
}

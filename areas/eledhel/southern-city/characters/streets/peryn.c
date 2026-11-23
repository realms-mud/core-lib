//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Peryn");
    short("Peryn, a weaver's clerk");
    description("Peryn's golden hair is pinned up, and violet eyes "
        "brighten as she discusses her cloth samples. She is persuasive "
        "and optimistic.");
    Gender("female");
    Race("maegenstryd");
    SetUpPersonaOfLevel("grocer", 4);
    addTrait("/lib/instances/traits/eyes/violet.c");
    addTrait("/lib/instances/traits/hair/golden.c");
    addTrait("/lib/instances/traits/personality/persuasive.c");
    addTrait("/lib/instances/traits/personality/optimistic.c");
    addConversation(
        "/areas/eledhel/southern-city/characters/streets/"
        "perynConversation.c");
}

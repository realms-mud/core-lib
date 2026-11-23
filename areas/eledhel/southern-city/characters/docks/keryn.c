//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Keryn");
    short("Keryn, a harbor sailor");
    description("Keryn's golden hair is knotted under a cap, and "
        "light-blue eyes watch the harbor. She is spirited and brave.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("fisher", 5);
    addTrait("/lib/instances/traits/eyes/light-blue.c");
    addTrait("/lib/instances/traits/hair/golden.c");
    addTrait("/lib/instances/traits/personality/spirited.c");
    addTrait("/lib/instances/traits/personality/brave.c");
    addConversation(
        "/areas/eledhel/southern-city/characters/docks/"
        "kerynConversation.c");
}

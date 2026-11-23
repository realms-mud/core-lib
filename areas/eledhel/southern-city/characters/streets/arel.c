//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Arel");
    short("Arel, a market shopper");
    description("Arel's brunette hair is tied in a scarf, and brown "
        "eyes check her purchases. She is spirited and generous.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("grocer", 3);
    addTrait("/lib/instances/traits/eyes/brown.c");
    addTrait("/lib/instances/traits/hair/brunette.c");
    addTrait("/lib/instances/traits/personality/spirited.c");
    addTrait("/lib/instances/traits/personality/generous.c");
    addConversation(
        "/areas/eledhel/southern-city/characters/streets/"
        "arelConversation.c");
}

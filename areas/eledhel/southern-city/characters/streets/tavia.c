//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Tavia");
    short("Tavia, a provision buyer");
    description("Tavia's brunette hair is twisted into a knot, and "
        "light-brown eyes track each item on her list. She is focused "
        "and honest.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("grocer", 3);
    addTrait("/lib/instances/traits/eyes/light-brown.c");
    addTrait("/lib/instances/traits/hair/brunette.c");
    addTrait("/lib/instances/traits/personality/focused.c");
    addTrait("/lib/instances/traits/personality/honest.c");
    addConversation(
        "/areas/eledhel/southern-city/characters/streets/"
        "taviaConversation.c");
}

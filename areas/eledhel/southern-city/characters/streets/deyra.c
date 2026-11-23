//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Deyra");
    short("Deyra, a provision shopper");
    description("Deyra's auburn hair is braided over one shoulder, and "
        "violet eyes track her list. She is pragmatic and focused.");
    Gender("female");
    Race("maegenstryd");
    SetUpPersonaOfLevel("grocer", 3);
    addTrait("/lib/instances/traits/eyes/violet.c");
    addTrait("/lib/instances/traits/hair/auburn.c");
    addTrait("/lib/instances/traits/personality/pragmatic.c");
    addTrait("/lib/instances/traits/personality/focused.c");
    addConversation(
        "/areas/eledhel/southern-city/characters/streets/"
        "deyraConversation.c");
}

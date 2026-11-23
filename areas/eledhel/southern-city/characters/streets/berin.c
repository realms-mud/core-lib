//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Berin");
    short("Berin, a baker's assistant");
    description("Berin's brown hair is tucked under a cap, and his "
        "hazel eyes are kind. He is diligent about morning bread runs.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("grocer", 3);
    addTrait("/lib/instances/traits/eyes/hazel.c");
    addTrait("/lib/instances/traits/hair/brown.c");
    addTrait("/lib/instances/traits/personality/kind.c");
    addTrait("/lib/instances/traits/personality/diligent.c");
    addConversation(
        "/areas/eledhel/southern-city/characters/streets/"
        "berinConversation.c");
}

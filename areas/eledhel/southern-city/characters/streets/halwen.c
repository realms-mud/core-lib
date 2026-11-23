//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Halwen");
    short("Halwen, a wainwright's customer");
    description("Halwen's steel-gray hair is swept from hazel eyes. He "
        "is pragmatic and patient with every repair.");
    Gender("male");
    Race("maegenstryd");
    SetUpPersonaOfLevel("blacksmith", 4);
    addTrait("/lib/instances/traits/eyes/hazel.c");
    addTrait("/lib/instances/traits/hair/steel-gray.c");
    addTrait("/lib/instances/traits/personality/pragmatic.c");
    addTrait("/lib/instances/traits/personality/patient.c");
    addConversation(
        "/areas/eledhel/southern-city/characters/streets/"
        "halwenConversation.c");
}

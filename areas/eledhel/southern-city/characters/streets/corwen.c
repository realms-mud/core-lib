//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Corwen");
    short("Corwen, an inn guest");
    description("Corwen's sandy hair is tucked behind green eyes. He is "
        "shy with strangers but open-minded about the city.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("innkeeper", 3);
    addTrait("/lib/instances/traits/eyes/green.c");
    addTrait("/lib/instances/traits/hair/sandy-brown.c");
    addTrait("/lib/instances/traits/personality/shy.c");
    addTrait("/lib/instances/traits/personality/openminded.c");
    addConversation(
        "/areas/eledhel/southern-city/characters/streets/"
        "corwenConversation.c");
}

//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Neral");
    short("Neral, a pottery buyer");
    description("Neral's caramel-brown hair falls over his brown eyes. "
        "He is humble and trusting with neighbors.");
    Gender("male");
    Race("maegenstryd");
    SetUpPersonaOfLevel("grocer", 3);
    addTrait("/lib/instances/traits/eyes/brown.c");
    addTrait("/lib/instances/traits/hair/caramel-brown.c");
    addTrait("/lib/instances/traits/personality/humble.c");
    addTrait("/lib/instances/traits/personality/trusting.c");
    addConversation(
        "/areas/eledhel/southern-city/characters/streets/"
        "neralConversation.c");
}

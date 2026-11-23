//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Paven");
    short("Paven, a mason's apprentice");
    description("Paven's ash-brown hair is cut short, and green eyes "
        "study the paving. He is pragmatic and patient.");
    Gender("male");
    Race("maegenstryd");
    SetUpPersonaOfLevel("blacksmith", 4);
    addTrait("/lib/instances/traits/eyes/green.c");
    addTrait("/lib/instances/traits/hair/ash-brown.c");
    addTrait("/lib/instances/traits/personality/pragmatic.c");
    addTrait("/lib/instances/traits/personality/patient.c");
    addConversation(
        "/areas/eledhel/southern-city/characters/streets/"
        "pavenConversation.c");
}

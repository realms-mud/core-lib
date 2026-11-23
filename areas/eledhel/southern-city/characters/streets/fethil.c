//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Fethil");
    short("Fethil, a city guard");
    description("Fethil's raven-black hair is bound close, and gray eyes "
        "watch the crossing. She is disciplined and honorable.");
    Gender("female");
    Race("maegenstryd");
    SetUpPersonaOfLevel("city guard", 5);
    addTrait("/lib/instances/traits/eyes/gray.c");
    addTrait("/lib/instances/traits/hair/raven.c");
    addTrait("/lib/instances/traits/personality/disciplined-warrior.c");
    addTrait("/lib/instances/traits/personality/honorable.c");
    addConversation(
        "/areas/eledhel/southern-city/characters/streets/"
        "fethilConversation.c");
}

//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Elset");
    short("Elset, a neighborhood courier");
    description("Elset's auburn hair is tied back from green eyes. "
        "She is quick-witted and patient with her route.");
    Gender("female");
    Race("maegenstryd");
    SetUpPersonaOfLevel("city guard", 4);
    addTrait("/lib/instances/traits/eyes/green.c");
    addTrait("/lib/instances/traits/hair/auburn.c");
    addTrait("/lib/instances/traits/personality/quick-witted.c");
    addTrait("/lib/instances/traits/personality/patient.c");
    addConversation(
        "/areas/eledhel/southern-city/characters/streets/"
        "elsetConversation.c");
}

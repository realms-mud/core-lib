//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Quelan");
    short("Quelan, a market carter");
    description("Quelan's silver hair is tied at the nape, and sky-blue "
        "eyes pick a clear path for his handcart. He is quick-witted "
        "and resolute.");
    Gender("male");
    Race("halfling");
    SetUpPersonaOfLevel("farmer", 4);
    addTrait("/lib/instances/traits/eyes/sky-blue.c");
    addTrait("/lib/instances/traits/hair/silver.c");
    addTrait("/lib/instances/traits/personality/quick-witted.c");
    addTrait("/lib/instances/traits/personality/resolute.c");
    addConversation(
        "/areas/eledhel/southern-city/characters/streets/"
        "quelanConversation.c");
}

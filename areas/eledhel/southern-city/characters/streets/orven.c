//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Orven");
    short("Orven, a message carrier");
    description("Orven's salt-and-pepper hair is swept back from brown "
        "eyes. He is secretive but quick-witted.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("city guard", 4);
    addTrait("/lib/instances/traits/eyes/brown.c");
    addTrait("/lib/instances/traits/hair/salt-and-pepper.c");
    addTrait("/lib/instances/traits/personality/secretive.c");
    addTrait("/lib/instances/traits/personality/quick-witted.c");
    addConversation(
        "/areas/eledhel/southern-city/characters/streets/"
        "orvenConversation.c");
}

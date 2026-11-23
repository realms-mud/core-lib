//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Grevan");
    short("Grevan, a cargo tally runner");
    description("Grevan's ash-brown hair is combed back from gray eyes. "
        "He is rational and honest about every tally.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("grocer", 4);
    addTrait("/lib/instances/traits/eyes/gray.c");
    addTrait("/lib/instances/traits/hair/ash-brown.c");
    addTrait("/lib/instances/traits/personality/rational.c");
    addTrait("/lib/instances/traits/personality/honest.c");
    addConversation(
        "/areas/eledhel/southern-city/characters/docks/"
        "grevanConversation.c");
}

//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Hethin");
    short("Hethin, a market shopper");
    description("Hethin's copper hair curls around bright blue eyes. "
        "She is talkative and optimistic about the day's errands.");
    Gender("female");
    Race("maegenstryd");
    SetUpPersonaOfLevel("grocer", 3);
    addTrait("/lib/instances/traits/eyes/blue.c");
    addTrait("/lib/instances/traits/hair/copper.c");
    addTrait("/lib/instances/traits/personality/talkative.c");
    addTrait("/lib/instances/traits/personality/optimistic.c");
    addConversation(
        "/areas/eledhel/southern-city/characters/streets/"
        "hethinConversation.c");
}

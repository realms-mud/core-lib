//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Rethen");
    short("Rethen, a brewery worker");
    description("Rethen's ginger hair is swept back from gray eyes. "
        "He is gregarious and talkative on his delivery rounds.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("grocer", 4);
    addTrait("/lib/instances/traits/eyes/light-gray.c");
    addTrait("/lib/instances/traits/hair/ginger.c");
    addTrait("/lib/instances/traits/personality/gregarious.c");
    addTrait("/lib/instances/traits/personality/talkative.c");
    addConversation(
        "/areas/eledhel/southern-city/characters/streets/"
        "rethenConversation.c");
}

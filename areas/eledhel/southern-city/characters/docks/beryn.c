//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Beryn");
    short("Beryn, a fish seller");
    description("Beryn's ginger hair is tied up from the work, and "
        "blue-green eyes sort the catch. She is gregarious and honest.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("fisher", 4);
    addTrait("/lib/instances/traits/eyes/blue-green.c");
    addTrait("/lib/instances/traits/hair/ginger.c");
    addTrait("/lib/instances/traits/personality/gregarious.c");
    addTrait("/lib/instances/traits/personality/honest.c");
    addConversation(
        "/areas/eledhel/southern-city/characters/docks/"
        "berynConversation.c");
}

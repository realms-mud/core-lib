//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Telya");
    short("Telya, a jeweler's apprentice");
    description("Telya's burgundy hair is pinned beneath a scarf, and "
        "light-violet eyes guard her sample case. She is ambitious and "
        "secretive.");
    Gender("female");
    Race("dwarf");
    SetUpPersonaOfLevel("grocer", 4);
    addTrait("/lib/instances/traits/eyes/light-violet.c");
    addTrait("/lib/instances/traits/hair/burgundy.c");
    addTrait("/lib/instances/traits/personality/ambitious.c");
    addTrait("/lib/instances/traits/personality/secretive.c");
    addConversation(
        "/areas/eledhel/southern-city/characters/streets/"
        "telyaConversation.c");
}

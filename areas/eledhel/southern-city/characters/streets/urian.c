//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Urian");
    short("Urian, a street hawker");
    description("Urian's black hair is slicked back, and copper-blue "
        "eyes sparkle as he bargains. He is witty and gregarious.");
    Gender("male");
    Race("maegenstryd");
    SetUpPersonaOfLevel("grocer", 3);
    addTrait("/lib/instances/traits/eyes/copper-blue.c");
    addTrait("/lib/instances/traits/hair/black.c");
    addTrait("/lib/instances/traits/personality/witty.c");
    addTrait("/lib/instances/traits/personality/gregarious.c");
    addConversation(
        "/areas/eledhel/southern-city/characters/streets/"
        "urianConversation.c");
}

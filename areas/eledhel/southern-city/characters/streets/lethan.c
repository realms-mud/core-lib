//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Lethan");
    short("Lethan, a city watchman");
    description("Lethan's black hair is neatly trimmed, and gray eyes "
        "track each cart. He is disciplined and just.");
    Gender("male");
    Race("maegenstryd");
    SetUpPersonaOfLevel("city guard", 5);
    addTrait("/lib/instances/traits/eyes/gray.c");
    addTrait("/lib/instances/traits/hair/black.c");
    addTrait("/lib/instances/traits/personality/disciplined-warrior.c");
    addTrait("/lib/instances/traits/personality/just.c");
    addConversation(
        "/areas/eledhel/southern-city/characters/streets/"
        "lethanConversation.c");
}

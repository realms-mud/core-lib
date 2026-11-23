//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Sileth");
    short("Sileth, a temple attendant");
    description("Sileth's pearl-white hair is braided simply, and "
        "light-gray eyes are calm. She is pious and humble.");
    Gender("female");
    Race("maegenstryd");
    SetUpPersonaOfLevel("grocer", 3);
    addTrait("/lib/instances/traits/eyes/light-gray.c");
    addTrait("/lib/instances/traits/hair/pearl-white.c");
    addTrait("/lib/instances/traits/personality/pious.c");
    addTrait("/lib/instances/traits/personality/humble.c");
    addConversation(
        "/areas/eledhel/southern-city/characters/streets/"
        "silethConversation.c");
}

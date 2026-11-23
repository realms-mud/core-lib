//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Norien");
    short("Norien, a neighborhood baker");
    description("Norien's honey-brown hair is dusted with flour, and "
        "blue eyes watch the oven. She is optimistic and diligent.");
    Gender("female");
    Race("maegenstryd");
    SetUpPersonaOfLevel("grocer", 4);
    addTrait("/lib/instances/traits/eyes/blue.c");
    addTrait("/lib/instances/traits/hair/honey-brown.c");
    addTrait("/lib/instances/traits/personality/optimistic.c");
    addTrait("/lib/instances/traits/personality/diligent.c");
    addConversation(
        "/areas/eledhel/southern-city/characters/streets/"
        "norienConversation.c");
}
